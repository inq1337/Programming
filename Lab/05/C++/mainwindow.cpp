#include "mainwindow.hpp"
#include "ui_mainwindow.h"

QByteArray readBytes(const QImage& img, uint begin, uint length); //main.cpp
void writeBytes(QImage& img, uint begin, QByteArray& byteArray); //main.cpp

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->messageFrame, &QTextEdit::textChanged, this, &MainWindow::messageChanged);
    connect(ui->decodeButton, &QPushButton::clicked, this, &MainWindow::decodeText);
    connect(ui->encodeButton, &QPushButton::clicked, this, &MainWindow::encodeText);

    isLoaded = false;
}

void MainWindow::loadImage()
{
    isLoaded = false;

    QString path = QFileDialog::getOpenFileName(this, "Открыть изображение", "", "Допустимые форматы (*.png)");

    if (!image.load(path, "PNG")) {
        ui->outputLabel->setText("Изображение не загружено");
        return;
    }
    image.convertTo(QImage::Format_ARGB32);
    imageCapacity = (image.width() * image.height() * 3) / 8 - indicator.size() - 4;
    ui->outputLabel->setText("Изображение успешно загружено");

    isLoaded = true;
}

void MainWindow::saveImage()
{
    if (!isLoaded) {
        ui->outputLabel->setText("Изображение не загружено в программу");
        return;
    }

    QString path = QFileDialog::getSaveFileName(this, "Сохранить изображение", "", "Допустимые форматы (*.png)");
    if (image.save(path, "PNG")) {
        ui->outputLabel->setText(QString("Изображение успешно сохранено в %1").arg(path));
    }
    else {
        ui->outputLabel->setText("Не удалось сохранить изображение");
    }
}

void MainWindow::encodeText()
{
    if (!isLoaded) {
        ui->outputLabel->setText("Не удалось загрузить изображение");
        return;
    }

    usedBytes = ui->messageFrame->toPlainText().toUtf8().size();

    if (imageCapacity < usedBytes) {
        ui->outputLabel->setText("Ошибка. Недостаточно места!");
        return;
    }

    QByteArray byteArray;
    byteArray.push_back(indicator);
    for (int i = 4 - 1; i >= 0; --i) {
        byteArray.push_back((usedBytes >> i*8) & 0xff);
    }
    byteArray.push_back(ui->messageFrame->toPlainText().toUtf8());

    writeBytes(image, 0, byteArray);

    ui->outputLabel->setText("Сообщение успешно добавлено в изображение");
}

void MainWindow::decodeText()
{
    if (!isLoaded) {
        ui->outputLabel->setText("Не удалось загрузить изображение");
        return;
    }

    int headerSize = indicator.size() + 4;
    QByteArray byteArray;
    byteArray = readBytes(image, 0, headerSize);

    for (uint i = 0; i < indicator.size(); ++i) {
        if (indicator[i] != byteArray[i]) {
            ui->outputLabel->setText("Сообщение не обнаружено");
            return;
        }
    }

    uint messageSize = 0;
    for (uint i = indicator.size(); i < indicator.size() + 4; ++i) {
        messageSize = (messageSize << 8) + static_cast<unsigned char>(byteArray[i]);
    }
    byteArray = readBytes(image, headerSize, messageSize);

    ui->messageFrame->setText(QString::fromUtf8(byteArray));
    ui->outputLabel->setText(QString("Присутствует сообщение длиной %1 байт").arg(messageSize));
}

void MainWindow::messageChanged()
{
    if (imageCapacity < 0) return;
    usedBytes = ui->messageFrame->toPlainText().toUtf8().size();

    if (imageCapacity < usedBytes) {
        ui->outputLabel->setText(QString("Размер сообщения превышен на %1 байт").arg(usedBytes - imageCapacity));
    } else {
        ui->outputLabel->setText(QString("Ещё можно ввести: %1 байт").arg(imageCapacity - usedBytes));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

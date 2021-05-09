from PySide6.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout
from PySide6.QtWidgets import QPushButton, QTextEdit, QFrame, QLabel, QSizePolicy, QFileDialog
from PySide6.QtCore import QByteArray, Slot, Qt, QMetaObject
from PySide6.QtGui import QImage, QPalette, QBrush, QColor, QFont
from main import read_bytes, write_bytes, set_bit, get_bit

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(400, 300)
        MainWindow.setWindowTitle(u"\u0421\u0442\u0435\u0433\u0430\u043d\u043e\u0433\u0440\u0430\u0444\u0438\u044f")
        MainWindow.setStyleSheet(u"QMainWindow {\n"
                                "background-color: #f8f9fa;\n"
                                "}\n"
                                "QPushButton {\n"
                                "color: white;\n"
                                "border:1px solid rgb(13,110,253);\n"
                                "border-radius: 6px;\n"
                                "background-color: rgb(13,110,253);\n"
                                "}\n"
                                "QPushButton:focus {\n"
                                "border: 3px solid rgb(11,94,215);\n"
                                "outline: none;\n"
                                "}\n"
                                "QPushButton:hover {\n"
                                "border-color: rgb(11,94,215);\n"
                                "background-color: rgb(11,94,215);\n"
                                "}\n"
                                "QTextEdit {\n"
                                "background-color: white;\n"
                                "border: 1px solid rgb(206,212,218);\n"
                                "border-radius: 6px;\n"
                                "color:rgb(0, 0, 0);\n"
                                "}\n"
                                "QTextEdit:focus {\n"
                                "border: 2px solid rgb(143,184,243);\n"
                                "}")

        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.load_button = QPushButton(self.centralwidget)
        self.load_button.setObjectName(u"load_button")
        font = QFont()
        font.setPointSize(9)
        self.load_button.setFont(font)
        self.load_button.setStyleSheet(u"")
        self.load_button.setText(u"\u0417\u0430\u0433\u0440\u0443\u0437\u0438\u0442\u044c \u0438\u0437\u043e\u0431\u0440\u0430\u0436\u0435\u043d\u0438\u0435")

        self.horizontalLayout.addWidget(self.load_button)

        self.save_button = QPushButton(self.centralwidget)
        self.save_button.setObjectName(u"save_button")
        self.save_button.setFont(font)
        self.save_button.setStyleSheet(u"")
        self.save_button.setText(u"\u0421\u043e\u0445\u0440\u0430\u043d\u0438\u0442\u044c \u0438\u0437\u043e\u0431\u0440\u0430\u0436\u0435\u043d\u0438\u0435")

        self.horizontalLayout.addWidget(self.save_button)


        self.verticalLayout.addLayout(self.horizontalLayout)

        self.message_frame = QTextEdit(self.centralwidget)
        self.message_frame.setObjectName(u"message_frame")
        sizePolicy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(1)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.message_frame.sizePolicy().hasHeightForWidth())
        self.message_frame.setSizePolicy(sizePolicy)
        font.setPointSize(10)
        self.message_frame.setFont(font)
        font.setPointSize(9)        
        self.message_frame.setStyleSheet(u"")
        self.message_frame.setFrameShape(QFrame.StyledPanel)
        self.message_frame.setMarkdown(u"")
        self.message_frame.setHtml(u"")
        self.message_frame.setPlaceholderText(u"\u0412\u0432\u0435\u0434\u0438\u0442\u0435 \u0441\u043e\u043e\u0431\u0449\u0435\u043d\u0438\u0435")

        self.verticalLayout.addWidget(self.message_frame)

        self.output_label = QLabel(self.centralwidget)
        self.output_label.setObjectName(u"output_label")
        sizePolicy1 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy1.setHorizontalStretch(1)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.output_label.sizePolicy().hasHeightForWidth())
        self.output_label.setSizePolicy(sizePolicy1)
        font1 = QFont()
        self.output_label.setFont(font1)
        self.output_label.setText(u"")
        self.output_label.setScaledContents(False)
        self.output_label.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignTop)
        self.output_label.setWordWrap(True)

        self.verticalLayout.addWidget(self.output_label)

        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.decode_button = QPushButton(self.centralwidget)
        self.decode_button.setObjectName(u"decode_button")
        palette = QPalette()
        brush = QBrush(QColor(255, 255, 255, 255))
        brush.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.WindowText, brush)
        brush1 = QBrush(QColor(13, 110, 253, 255))
        brush1.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Button, brush1)
        palette.setBrush(QPalette.Active, QPalette.Text, brush)
        palette.setBrush(QPalette.Active, QPalette.ButtonText, brush)
        palette.setBrush(QPalette.Active, QPalette.Base, brush1)
        palette.setBrush(QPalette.Active, QPalette.Window, brush1)
        palette.setBrush(QPalette.Active, QPalette.PlaceholderText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.WindowText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.Button, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Text, brush)
        palette.setBrush(QPalette.Inactive, QPalette.ButtonText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.Base, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Window, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.PlaceholderText, brush)
        palette.setBrush(QPalette.Disabled, QPalette.WindowText, brush)
        palette.setBrush(QPalette.Disabled, QPalette.Button, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Text, brush)
        palette.setBrush(QPalette.Disabled, QPalette.ButtonText, brush)
        palette.setBrush(QPalette.Disabled, QPalette.Base, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Window, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.PlaceholderText, brush)
        self.decode_button.setPalette(palette)
        self.decode_button.setFont(font)
        self.decode_button.setStyleSheet(u"")
        self.decode_button.setText(u"\u0414\u0435\u043a\u043e\u0434\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0442\u0435\u043a\u0441\u0442")

        self.horizontalLayout_2.addWidget(self.decode_button)

        self.encode_button = QPushButton(self.centralwidget)
        self.encode_button.setObjectName(u"encode_button")
        self.encode_button.setFont(font)
        self.encode_button.setStyleSheet(u"")
        self.encode_button.setText(u"\u0417\u0430\u043a\u043e\u0434\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0442\u0435\u043a\u0441\u0442")

        self.horizontalLayout_2.addWidget(self.encode_button)


        self.verticalLayout.addLayout(self.horizontalLayout_2)

        MainWindow.setCentralWidget(self.centralwidget)
        QWidget.setTabOrder(self.load_button, self.save_button)
        QWidget.setTabOrder(self.save_button, self.encode_button)
        QWidget.setTabOrder(self.encode_button, self.decode_button)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        pass


class MainWindow(QMainWindow):
    indicator = bytes((0b11100010, 0b10011101, 0b10100100))
    image_capacity = 0
    used_capacity = 0
    is_loaded = False
    image = QImage()


    def __init__(self):
        super(MainWindow, self).__init__(None)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.ui.message_frame.textChanged.connect(self.message_changed)
        self.ui.load_button.clicked.connect(self.read_image)
        self.ui.save_button.clicked.connect(self.write_image)
        self.ui.encode_button.clicked.connect(self.encode_text)
        self.ui.decode_button.clicked.connect(self.decode_text)

        
    @Slot()
    def read_image(self):
        self.is_loaded = False
        path, _ = QFileDialog.getOpenFileName(self, "Открыть картинку", "", "Допустимые форматы (*.png)")

        if not self.image.load(path):
            self.ui.output_label.setText("Изображение не загружено!")
            return

        self.image.convertTo(QImage.Format_ARGB32)
        self.image_capacity = (self.image.width() * self.image.height() * 3) // 8 - len(self.indicator) - 4
        self.ui.output_label.setText("Изображение успешно загружено")
        self.is_loaded = True
        
    @Slot()
    def write_image(self):
        if not self.is_loaded:
            self.ui.output_label.setText("Изображение не загружено в программу")
            return

        path, _ = QFileDialog.getSaveFileName(self, "Сохранить изображение", "", "Допустимые форматы (*.png)")

        if self.image.save(path, "PNG"):
            self.ui.output_label.setText(f"Изображение успешно сохранено в {path}")
            return
        else:
            self.ui.output_label.setText('Не удалось сохранить изображение')


    @Slot()
    def encode_text(self):
        if not self.is_loaded:
            self.ui.output_label.setText("Изображение не загружено в программу")
            return

        self.used_capacity = len(self.ui.message_frame.toPlainText())
        if self.image_capacity < self.used_capacity:
            self.ui.output_label.setText("Ошибка. Недостаточно места!")
            return
            
        byte_array = QByteArray()
        byte_array.push_back(self.ui.message_frame.toPlainText().encode())
        for i in range(4):
            byte_array.push_front(bytes(((self.used_capacity >> i * 8) & 0xff,)))
        for i in range(len(MainWindow.indicator) - 1, -1, -1):
            byte_array.push_front(bytes((MainWindow.indicator[i],)))

        write_bytes(self.image, byte_array, 0)

        self.ui.output_label.setText("Сообщение успешно добавлено в изображение")
        
    @Slot()
    def decode_text(self):
        if not self.is_loaded:
            self.ui.output_label.setText('Изображение не загружено в программу')
            return

        header_size = len(self.indicator) + 4
        byte_array = read_bytes(self.image, 0, header_size)

        for i in range(0, len(self.indicator)):
            if bytes((self.indicator[i],)) != byte_array[i]:
                self.ui.output_label.setText("Сообщение не обнаружено")
                return

        message_size = 0
        for i in range(len(self.indicator), len(self.indicator) + 4):
            message_size = (message_size << 8) + int.from_bytes(byte_array[i], "big")
        byte_array.clear()
        byte_array = read_bytes(self.image, header_size, message_size)

        self.ui.message_frame.setText(bytes(byte_array).decode("utf-8"))
        self.ui.output_label.setText(f"Присутствует сообщение длиной {message_size} байт.")

    @Slot()
    def message_changed(self):
        if self.image_capacity < 0:
            return

        byte_array = QByteArray()
        byte_array.push_back(self.ui.message_frame.toPlainText().encode())
        self.used_capacity = len(self.ui.message_frame.toPlainText())

        if self.image_capacity < self.used_capacity:
            self.ui.output_label.setText(f"Размер сообщения превышен на: {self.used_capacity - self.image_capacity} байт.")
        else:
            self.ui.output_label.setText(f"Ещё можно ввести: {self.image_capacity - self.used_capacity} байт.")

#include <iostream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>

using json = nlohmann::json;
using namespace std;
using namespace httplib;

string GetTime();
json GetWeather();

bool is_empty_file(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


void gen_response(const Request& req, Response& res)
{   
    json scache;
    std::ifstream rc("cache.json");
    bool not_exist_cache = !rc.is_open() or is_empty_file(rc);

    if (not_exist_cache)
    {
        scache = GetWeather();
        std::ofstream wc("cache.json");
        cout << "Generating cache..." << endl;
        wc << std::setw(2) << scache << std::endl;
    }
    else
    {
        rc >> scache;
        cout << "Cache succesfully read" << endl;
    }
    string temp = scache;
    json cache = json::parse(temp);

    int curr_hour;
    long unixtime;
    bool do_need_update = true;

    json curr_time_full = json::parse(GetTime());
    unixtime = curr_time_full["unixtime"];
    for (int i = 0; i < 48; i++)
    {
        long w_unixtime = cache["hourly"][i]["dt"];
        if (unixtime < w_unixtime)
        {
            curr_hour = i;
            do_need_update = false;
            break;
        }
    }

    if (do_need_update)
    {
        scache = GetWeather();
        std::ofstream wc("cache.json");
        wc << std::setw(2) << scache << std::endl;
        cout << "Generating cache..." << endl;
    }


    string widget;
    ifstream rw("template.html");
    if (rw.is_open())
    {
        getline(rw, widget, '\0');
    }
    else
        cout << "Can`t open template";

    string r1 = "{hourly[i].weather[0].description}";
    string r2 = "{hourly[i].weather[0].icon}";
    string r3 = "{hourly[i].temp}";

    string r4 = std::to_string(int(std::round(cache["hourly"][curr_hour]["temp"].get<double>())));

    widget.replace(widget.find(r1), r1.length(), cache["hourly"][curr_hour]["weather"][0]["description"]);
    widget.replace(widget.find(r2), r2.length(), cache["hourly"][curr_hour]["weather"][0]["icon"]);
    widget.replace(widget.find(r3), r3.length(), r4);
    widget.replace(widget.find(r3), r3.length(), r4);

	res.set_content(widget, "text/html");
}

int main()
{


	Server weather;
	weather.Get("/", gen_response);
	std::cout << "Start server... OK\n";
	weather.listen("localhost", 3000);
}




json GetWeather()
{
    Client get_time("http://api.openweathermap.org");
    auto res = get_time.Get("/data/2.5/onecall?id=524901&lat=44.95719&lon=34.11079&exclude=current,minutely,daily,alerts&units=metric&lang=ru&appid=bb693a45bf038ad8c1cc887c8a5bd872");
    if (res) {
        if (res->status == 200)
        {
            json result = res->body;
            return result;
        }
        else
        {
            std::cout << "Status code: " << res->status << std::endl;
        }
    }
    else
    {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }
}

string GetTime()
{
    Client get_time("http://worldtimeapi.org");
    auto res = get_time.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200)
        {
            string result = res->body;
            return result;
        }
        else
        {
            std::cout << "Status code: " << res->status << std::endl;
        }
    }
    else
    {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }
}
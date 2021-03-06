﻿#include <iostream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>

using json = nlohmann::json;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using namespace httplib;

void gen_response(const Request& req, Response& res);
void gen_response_raw(const Request& req, Response& res);

int main()
{
    Server weather;
    weather.Get("/", gen_response);
    weather.Get("/raw", gen_response_raw);
    cout << "Start server... OK\n";
    weather.listen("localhost", 3000);
}

json GetWeather()
{
    string req, adr, param, api;
    adr = "/data/2.5/onecall?id=524901&";
    param = "lat=44.95719&lon=34.11079&exclude=current,minutely,daily,alerts&units=metric&lang=ru&";
    api = "appid=bb693a45bf038ad8c1cc887c8a5bd872";
    req = adr + param + api;

    Client get_time("http://api.openweathermap.org");
    auto res = get_time.Get(req.c_str());
    if (res) {
        if (res->status == 200)
        {
            json result = res->body;
            return result;
        }
        else
        {
            cout << "Status code: " << res->status << endl;
        }
    }
    else
    {
        auto err = res.error();
        cout << "Error code: " << err << endl;
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
            cout << "Status code: " << res->status << endl;
        }
    }
    else
    {
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
}

bool is_empty_file(std::ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

json CacheGenerator(ifstream& ReadCache)
{
    json RawCache;
    RawCache = GetWeather();
    ofstream wc("cache.json");
    cout << "Generating cache..." << endl;
    wc << std::setw(2) << RawCache << std::endl;
    return RawCache;
}

string StringRemoover(string FToRemoove, json cache, int curr_hour)
{
    string r1 = "{hourly[i].weather[0].description}";
    string r2 = "{hourly[i].weather[0].icon}";
    string r3 = "{hourly[i].temp}";

    double tempd = cache["hourly"][curr_hour]["temp"];
    string temps = std::to_string(int(round(tempd)));
    string desk = cache["hourly"][curr_hour]["weather"][0]["description"];
    string icon = cache["hourly"][curr_hour]["weather"][0]["icon"];

    FToRemoove.replace(FToRemoove.find(r1), r1.length(), desk);
    FToRemoove.replace(FToRemoove.find(r2), r2.length(), icon);
    FToRemoove.replace(FToRemoove.find(r3), r3.length(), temps);
    FToRemoove.replace(FToRemoove.find(r3), r3.length(), temps);
    return FToRemoove;
}

int WhatHour(json cache)
{
    int curr_hour = 100;
    long unixtime;

    json curr_time_full = json::parse(GetTime());
    unixtime = curr_time_full["unixtime"];
    for (int i = 0; i < 48; i++)
    {
        long w_unixtime = cache["hourly"][i]["dt"];
        if (unixtime < w_unixtime)
        {
            curr_hour = i;
            break;
        }
    }
    return curr_hour;
}

json CacheReader(ifstream& rc)
{
    json RawCache;
    bool not_exist_cache = !rc.is_open() or is_empty_file(rc);

    if (not_exist_cache)
    {
        RawCache = CacheGenerator(rc);
    }
    else
    {
        rc >> RawCache;
        cout << "Cache succesfully read" << endl;
    }
    return RawCache;
}

void gen_response_raw(const Request& req, Response& res)
{
    ifstream rc("cache.json");
    json RawCache = CacheReader(rc);
    string temp = RawCache;
    json cache = json::parse(temp);
    int curr_hour = WhatHour(cache);

    if (curr_hour == 100)
    {
        RawCache = CacheGenerator(rc);
        temp = RawCache;
        cache = json::parse(temp);
    }

    json WeatherData;
    double tempd = cache["hourly"][curr_hour]["temp"];
    int tempi = round(tempd);
    string desk = cache["hourly"][curr_hour]["weather"][0]["description"];

    WeatherData["temperature"] = tempi;
    WeatherData["description"] = desk;
    res.set_content(WeatherData.dump(), "text/json");
}

void gen_response(const Request& req, Response& res)
{
    ifstream rc("cache.json");
    json RawCache = CacheReader(rc);
    string temp = RawCache;
    json cache = json::parse(temp);
    int curr_hour = WhatHour(cache);

    if (curr_hour == 100)
    {
        RawCache = CacheGenerator(rc);
        temp = RawCache;
        cache = json::parse(temp);
    }

    string widget;
    ifstream rw("template.html");
    if (rw.is_open())
    {
        getline(rw, widget, '\0');
    }
    else
        cout << "Can`t open template";

    string output = StringRemoover(widget, cache, curr_hour);
    res.set_content(output, "text/html");
}
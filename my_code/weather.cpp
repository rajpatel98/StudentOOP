#include <iostream>
#include <string>
#include <vector>
#include "weather.h"

using namespace std;

Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
}

Image::~Image() {
}

Image& Image::operator=(const Image& img2) {
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}




ostream& operator<<(ostream& os, const GPS& gps)
{
    os << "Latitude: " << gps.latitude << ", Longitude: " << gps.longitude;
    return os;
}

//Date::Date(int d, int m, int y): day(d), month(m), year(y){}
//
//ostream& operator<<(std::ostream& os, const Date& date)
//{
//    os << date.day << "/" << date.month << "/" << date.year << " ";
//    return os;
//}



ostream& operator<<(std::ostream& os, const WReading& wr)
{
    os << "Date: " << wr.date << " Temperature: " << wr.temperature;
    os << " Humidity: " << wr.humidity << " Humidity: " << wr.windspeed << " ";
    return os;
}


/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc): station_nm(nm), my_loc(loc){}

string Weather::get_name() const
{
    return station_nm;
}

int Weather::get_rating() const
{
    return rating;
}

void Weather::set_rating(int new_rating)
{
    rating = new_rating;
}

void Weather::add_reading(WReading wr)
{
    wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const Weather& w)
{
    os << "Name: " << w.station_nm << ", Rating: " << w.rating;
    os << ", Loc: " << w.my_loc << "\nReadings: \n";
    for (int i = 0; i < w.wreadings.size(); i++)
    {
        os << w.wreadings[i] << endl;
    }
    return os;
}

#include <iostream>
#include <string>
#include <vector>
#include "weather.h"

using namespace std;

Image::Image(int w, int h, std::string flnm): width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2)
{
    copy_fields(img2);
}

Image::~Image()
{
    if (image_buf)
    {
        delete[] image_buf;
        image_buf = nullptr;
    }
}

Image& Image::operator=(const Image& img2)
{
    if (image_buf)
    {
        delete[] image_buf;
        image_buf = nullptr;
    }
    copy_fields(img2);
    return *this;
}

int Image::image_sz()
{
    return width * height;
}


void Image::copy_fields(const Image& img2)
{
    width = img2.width;
    height = img2.height;
    filename = img2.filename;
    image_buf = new char[image_sz()];
    for (int i = 0; i < 100; i++)
    {
        image_buf[i] = img2.image_buf[i];
    }
    
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s)
{
    return "Displaying image " + s;
}




ostream& operator<<(ostream& os, const GPS& gps)
{
    os << "Latitude: " << gps.latitude << ", Longitude: " << gps.longitude;
    return os;
}



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

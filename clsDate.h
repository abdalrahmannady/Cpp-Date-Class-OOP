#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    // =========================
    // Constructors
    // =========================

    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = (short)now->tm_mday;
        _Month = (short)(now->tm_mon + 1);
        _Year = (short)(now->tm_year + 1900);
    }

    clsDate(short Day, short Month, short Year)
        : _Day(Day), _Month(Month), _Year(Year) {
    }

    clsDate(std::string sDate)
    {
        std::vector<std::string> vDate = SplitDate(sDate);
        if (vDate.size() == 3) {
            _Day = (short)stoi(vDate[0]);
            _Month = (short)stoi(vDate[1]);
            _Year = (short)stoi(vDate[2]);
        }
    }

    // =========================
    // Properties (Getters)
    // =========================
    short Day() const { return _Day; }
    short Month() const { return _Month; }
    short Year() const { return _Year; }

    // =========================
    // Static Helpers
    // =========================

    static std::vector<std::string> SplitDate(std::string text, std::string delimeter = "/")
    {
        std::vector<std::string> result;
        size_t pos = 0;
        std::string token;
        while ((pos = text.find(delimeter)) != std::string::npos) {
            token = text.substr(0, pos);
            if (!token.empty()) result.push_back(token);
            text.erase(0, pos + delimeter.length());
        }
        result.push_back(text);
        return result;
    }

    static bool IsLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    static short DaysInMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12) return 0;
        short days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    static bool IsValidDate(const clsDate& Date)
    {
        return (Date._Month >= 1 && Date._Month <= 12) &&
            (Date._Day >= 1 && Date._Day <= DaysInMonth(Date._Month, Date._Year));
    }

    static std::string ToString(const clsDate& Date)
    {
        return std::to_string(Date._Day) + "/" +
            std::to_string(Date._Month) + "/" +
            std::to_string(Date._Year);
    }

    static bool IsBefore(const clsDate& d1, const clsDate& d2)
    {
        return (d1._Year < d2._Year) ? true :
            (d1._Year > d2._Year) ? false :
            (d1._Month < d2._Month) ? true :
            (d1._Month > d2._Month) ? false : (d1._Day < d2._Day);
    }

    static bool IsEqual(const clsDate& d1, const clsDate& d2)
    {
        return d1._Year == d2._Year && d1._Month == d2._Month && d1._Day == d2._Day;
    }

    static clsDate AddOneDay(clsDate Date)
    {
        if (Date._Day == DaysInMonth(Date._Month, Date._Year)) {
            Date._Day = 1;
            if (Date._Month == 12) {
                Date._Month = 1;
                Date._Year++;
            }
            else {
                Date._Month++;
            }
        }
        else {
            Date._Day++;
        }
        return Date;
    }

    static int DifferenceInDays(clsDate d1, clsDate d2, bool IncludeEndDay = false)
    {
        int days = 0;
        short swapSign = 1;

        if (!IsBefore(d1, d2)) {
            std::swap(d1, d2);
            swapSign = -1; 
        }

        while (IsBefore(d1, d2)) {
            d1 = AddOneDay(d1);
            days++;
        }

        return IncludeEndDay ? (days + 1) * swapSign : days * swapSign;
    }

    // =========================
    // Instance Methods (using const)
    // =========================

    std::string ToString() const {
        return ToString(*this);
    }

    bool IsValid() const {
        return IsValidDate(*this);
    }

    bool IsBefore(const clsDate& Date2) const {
        return IsBefore(*this, Date2);
    }

    bool IsEqual(const clsDate& Date2) const {
        return IsEqual(*this, Date2);
    }

    void AddOneDay() {
        *this = AddOneDay(*this);
    }

    int DifferenceInDays(const clsDate& Date2, bool IncludeEndDay = false) const {
        return DifferenceInDays(*this, Date2, IncludeEndDay);
    }

    // =========================
    // Operator Overloading
    // =========================

    bool operator==(const clsDate& other) const { return IsEqual(other); }

    bool operator<(const clsDate& other) const { return IsBefore(other); }

    friend std::ostream& operator<<(std::ostream& os, const clsDate& date) {
        os << date.ToString();
        return os;
    }
};


#include <string>
#include "oreno.h"
std::string clean_white_space(std::string a)
{
    std::string sum = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != ' ' && a[i] != 9)
        {
            sum = sum + a[i];
        }
    }
    return sum;
}
std::wstring clean_white_space(std::wstring a)
{
    std::wstring sum = L"";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != ' ' && a[i] != 9)
        {
            sum = sum + a[i];
        }
    }
    return sum;
}
void clean_null(std::string a)
{
    std::string sum = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != '\0')
        {
            sum += a[i];
        }
    }
    a = sum;
}
bool TryParse(std::string rawx)
{
    if (rawx.length() == 0)
    {
        return false;
    }
    else if (rawx == "")
    {
        return false;
    }
    int dotnum = 0, connum = 0;
    for (int i = 0; i < rawx.length(); i++)
    {
        if (rawx[i] != '\0' && rawx[i] != '-' && rawx[i] != '2' && rawx[i] != '.' && rawx[i] != ',' && rawx[i] != '0' && rawx[i] != '1' && rawx[i] != '3' && rawx[i] != '4' && rawx[i] != '5' && rawx[i] != '6' && rawx[i] != '7' && rawx[i] != '8' && rawx[i] != '9')
        {
            return false;
        }
    }
    for (int i = 0; i < rawx.length(); i++)
    {
        if (rawx[i] == '.')
        {
            dotnum++;
            if (i == rawx.length() - 1 || i == 0)
            {
                return false;
            }
        }
        if (rawx[i] == '-')
        {
            connum++;
            if (i != 0)
            {
                return false;
            }
        }
    }
    if (dotnum > 1)
    {
        return false;
    }
    if (connum > 1)
    {
        return false;
    }
    dotnum = 0;
    connum = 0;
    return true;
}
bool TryParse(std::wstring rawx)
{
    if (rawx.length() == 0)
    {
        return false;
    }
    else if (rawx == L"")
    {
        return false;
    }
    int dotnum = 0, connum = 0;
    for (int i = 0; i < rawx.length(); i++)
    {
        if (rawx[i] != '\0' && rawx[i] != '-' && rawx[i] != '2' && rawx[i] != ',' && rawx[i] != '.' && rawx[i] != '0' && rawx[i] != '1' && rawx[i] != '3' && rawx[i] != '4' && rawx[i] != '5' && rawx[i] != '6' && rawx[i] != '7' && rawx[i] != '8' && rawx[i] != '9')
        {
            return false;
        }
    }
    for (int i = 0; i < rawx.length(); i++)
    {
        if (rawx[i] == '.')
        {
            dotnum++;
            if (i == rawx.length() - 1 || i == 0)
            {
                return false;
            }
        }
        if (rawx[i] == '-')
        {
            connum++;
            if (i != 0)
            {
                return false;
            }
        }
    }
    if (dotnum > 1)
    {
        return false;
    }
    if (connum > 1)
    {
        return false;
    }
    dotnum = 0;
    connum = 0;
    return true;
}
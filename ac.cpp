#include <iostream>
#include <string>
#include <xstring>
#include <vector>
#include "C:\wx\VSC\Console\CPP\AdvancedCalculator\oreno.h"
#include <locale>
#include <codecvt>
#include "C:\wx\VSC\Console\CPP\AdvancedCalculator\orenomath.h"
#ifdef _WIN32
#define cls system("cls");
#define chcp system("chcp 65001");
#else 
#define cls system("clear");
#define chcp
#endif
using namespace std;
int main()
{
    chcp
    cls
	setlocale(LC_ALL, "");
    std::wcout.sync_with_stdio(false); // or set the C locale too
    std::wcout.imbue(std::locale(""));
    while (true)
    {
        int firstopnum = 0, veryfirstopnum = 0, lastopnum = 0, opin = -1, startop = 0, endop = 0, next = 0, parannum = 0;
        wstring RawInput = L"", AraInput = L"";
        getline(wcin, RawInput);
        RawInput = clean_white_space(RawInput);
        if (RawInput == L"q" || RawInput == L"Q")
        {
            exit(0);
        }
        else if (RawInput == L"cls" || RawInput == L"clear")
        {
            cls
            RawInput = L"";
        }
        for (int i = 0; i < RawInput.length(); i++)
        {

            if (RawInput[i] == '(')
            {
                opin = i;
                parannum++;
            }
        }
        for (int i = parannum; i > 0; i--)
        {
            wstring IRawInput = L"";
            bool inParan = false, isSingle = true, facto = false, squareroot = false;
            int startparan = -1, endparan = -1, paranfirstopnum = 0, paranveryfirstopnum = 0, paranlastopnum = 0;
            for (int x = 0; x < RawInput.length(); x++)
            {
                if (RawInput[x] == '(')
                {
                    startparan = x;
                    inParan = true;
                }
                else if (RawInput[x] == ')')
                {
                    inParan = 0;
                    endparan = x;
                    break;
                }
                else if (inParan)
                {

                    IRawInput += RawInput[x];
                }
            }
            for (int i = 0; i < IRawInput.length(); i++)
            {
                if (IRawInput[i] == '*' || IRawInput[i] == '/' || IRawInput[i] == '!')
                {
                    opin = i;
                    paranfirstopnum++;
                }
                else if (IRawInput[i] == '+' || IRawInput[i] == '-' && i != 0 && i != opin + 1)
                {
                    opin = i;
                    paranlastopnum++;
                }
                else if (IRawInput[i] == '^' ||IRawInput[i] == 'v')
                {
                    opin = i;
                    paranveryfirstopnum++;
                }
            }
            for (int x = 0; x < IRawInput.length(); x++)
            {
                if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '^' || IRawInput[x] == '-' && x != 0)
                {
                    isSingle = 0;
                }
            }
            if (isSingle)
            {
                if (IRawInput[0] == '-')
                {
                    IRawInput[0] = '0';
                }
                if (AraInput[AraInput.length() - 1] == '!')
                {
                    wstring zap = L"";
                    for (int i = 0; i < IRawInput.length() - 1; i++)
                    {
                        zap += IRawInput[i];
                    }
                    if (TryParse(zap))
                    {
                        int ap = stoi(zap);
                        for (int x = ap - 1; x > 1; x--)
                        {
                            ap *= x;
                        }
                        IRawInput = to_wstring(ap);
                    }
                }
                for (int x = 0; x < RawInput.length(); x++)
                {
                    if (x < startparan || x > endparan)
                    {
                        AraInput += RawInput[x];
                    }
                    else if (x == startparan)
                    {
                        AraInput += IRawInput;
                    }
                }
                RawInput = AraInput;
                AraInput = L"";
            }
            else
            {
                for (int i = paranveryfirstopnum; i > 0; i--)
                {
                    wstring sum = L"";
                    for (int x = next; x < IRawInput.length(); x++)
                    {
                        if (IRawInput[x] == '^' || IRawInput[x] == 'v')
                        {
                            if(IRawInput[x] == 'v'){squareroot = 1;}
                            else{squareroot = 0;}
                            opin = x;
                            break;
                        }
                    }
                    for (int x = opin + 1; x < IRawInput.length(); x++)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '^' || IRawInput[x] == '-' && x != opin + 1)
                        {
                            endop = x - 1;
                            break;
                        }
                        else if (x == IRawInput.length() - 1)
                        {
                            endop = x;
                            break;
                        }
                    }
                    for (int x = opin - 1; x >= 0 && !squareroot; x--)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '-' && IRawInput[x - 1] != '-' && x != 0)
                        {
                            startop = x + 1;
                            break;
                        }
                        else if (x == 0)
                        {
                            startop = x;
                            break;
                        }
                    }
                    if(squareroot){startop = opin;}
                    for (int x = startop; x <= endop && !squareroot; x++)
                    {
                        sum += IRawInput[x];
                    }
                    for(int x = startop + 1; x <= endop && squareroot; x++)
                    {
                        sum += IRawInput[x];
                    }
                    for (int x = 0; x <= IRawInput.length(); x++)
                    {
                        if (x < startop || x > endop)
                        {
                            AraInput += IRawInput[x];
                        }
                        else if (x == startop && !squareroot)
                        {
                            double a, b;
                            wstring rawx, rawy;
                            char op;
                            bool xturn = true;
                            for (int q = 0; q < sum.length(); q++)
                            {
                                if (sum[q] == '^')
                                {
                                    op = sum[q];
                                    xturn = false;
                                }
                                else if (xturn)
                                {
                                    rawx += sum[q];
                                }
                                else
                                {
                                    rawy += sum[q];
                                }
                            }
                            if (TryParse(rawx) && TryParse(rawy))
                            {
                                a = stod(rawx);
                                b = stod(rawy);

                                if (b < 0)
                                {
                                    double sumch = a;
                                    for (int z = abs(b) - 1; z > 0; z--)
                                    {
                                        sumch *= a;
                                    } // 2*2*2 = 2^3 = 2 times 2*=2 = 3-1times 2*=2
                                    AraInput += to_wstring(1 / sumch);
                                }
                                else if (b > 0)
                                {
                                    double sumch = a;
                                    for (int z = b - 1; z > 0; z--)
                                    {
                                        sumch *= a;
                                    }
                                    AraInput += to_wstring(sumch);
                                }
                                else
                                {
                                    AraInput += L"1";
                                }
                            }
                        }
                        else if(x == startop && squareroot)
                        {
                            if(TryParse(sum)){AraInput += to_wstring(sqrt(stod(sum)));}
                            else{cerr << "An error occured while parsing.\n";}
                        }
                    }
                    IRawInput = AraInput;
                    AraInput = L"";
                    sum = L"";
                    next = 0;
                    endop = 0;
                    startop = 0;
                    opin = 0;
                }
                next = 0;
                opin = 0;

                for (int i = paranfirstopnum; i > 0; i--)
                {
                    wstring sum = L"";
                    for (int x = next; x < IRawInput.length(); x++)
                    {
                        if (IRawInput[x] == '*' || IRawInput[x] == '/' || IRawInput[x] == '!')
                        {
                            if (IRawInput[x] == '!')
                            {
                                facto = 1;
                                opin = x;
                                break;
                            }
                            opin = x;
                            break;
                        }
                    }
                    for (int x = opin + 1; x < RawInput.length() && !facto; x++)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '-' && x != opin + 1)
                        {
                            endop = x - 1;
                            break;
                        }
                        else if (x == IRawInput.length() - 1)
                        {
                            endop = x;
                            break;
                        }
                    }
                    if (facto)
                    {
                        endop = opin;
                    }
                    for (int x = opin - 1; x >= 0; x--)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '-' && IRawInput[x - 1] != '-' && x != 0)
                        {
                            startop = x + 1;
                            break;
                        }
                    }
                    for (int x = startop; x <= endop; x++)
                    {
                        sum += IRawInput[x];
                    }
                    for (int x = 0; x <= IRawInput.length(); x++)
                    {
                        if (x < startop || x > endop)
                        {
                            AraInput += IRawInput[x];
                        }
                        else if (x == startop)
                        {

                            double a, b;
                            wstring rawx, rawy;
                            char op;
                            bool xturn = true;
                            for (int q = 0; q < sum.length(); q++)
                            {
                                if (sum[q] == '*' || sum[q] == '/' || sum[q] == '!')
                                {
                                    op = sum[q];
                                    xturn = false;
                                }
                                else if (xturn)
                                {
                                    rawx += sum[q];
                                }
                                else
                                {
                                    rawy += sum[q];
                                }
                            }
                            if (TryParse(rawx) && TryParse(rawy) && !facto)
                            {
                                a = stod(rawx);
                                b = stod(rawy);
                                if (op == '*')
                                {
                                    AraInput += to_wstring(a * b);
                                }
                                else
                                {
                                    AraInput += to_wstring(a / b);
                                }
                            }
                            else if (facto && TryParse(rawx))
                            {
                                int sumFact = stoi(rawx);
                                for (int v = sumFact - 1; v > 0; v--)
                                {
                                    sumFact *= v;
                                }
                                AraInput += to_wstring(sumFact);
                            }
                        }
                    }
                    IRawInput = AraInput;
                    AraInput = L"";
                    sum = L"";
                    next = 0;
                    endop = 0;
                    startop = 0;
                    opin = 0;
                }
                next = 0;
                opin = 0;
                for (int i = paranlastopnum; i > 0; i--)
                {
                    wstring sum = L"";
                    for (int x = next; x < IRawInput.length(); x++)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '-' && x != next)
                        {
                            opin = x;
                            break;
                        }
                    }
                    for (int x = opin + 1; x < IRawInput.length(); x++)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '-' && x != opin + 1)
                        {
                            endop = x - 1;
                            break;
                        }
                        else if (x == IRawInput.length() - 1)
                        {
                            endop = x;
                            break;
                        }
                    }
                    for (int x = opin - 1; x >= 0; x--)
                    {
                        if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '-' && IRawInput[x - 1] != '-' && x != 0)
                        {
                            startop = x + 1;
                            break;
                        }
                    }
                    for (int x = startop; x <= endop; x++)
                    {
                        sum += IRawInput[x];
                    }
                    for (int x = 0; x <= IRawInput.length(); x++)
                    {
                        if (x < startop || x > endop)
                        {
                            AraInput += IRawInput[x];
                        }
                        else if (x == startop)
                        {
                            double a, b;
                            wstring rawx, rawy;
                            char op;
                            bool xturn = true;
                            for (int q = 0; q < sum.length(); q++)
                            {
                                if (sum[q] == '+' || sum[q] == '-' && q != 0 && sum[q - 1] != '-')
                                {
                                    op = sum[q];
                                    xturn = false;
                                }
                                else if (xturn)
                                {
                                    rawx += sum[q];
                                }
                                else
                                {
                                    rawy += sum[q];
                                }
                            }
                            if (TryParse(rawx) && TryParse(rawy))
                            {
                                a = stod(rawx);
                                b = stod(rawy);
                                if (op == '+')
                                {
                                    AraInput += to_wstring(a + b);
                                }
                                else
                                {
                                    AraInput += to_wstring(a - b);
                                }
                            }
                        }
                    }
                    IRawInput = AraInput;
                    AraInput = L"";
                    sum = L"";
                    next = 0;
                    endop = 0;
                    startop = 0;
                    opin = 0;
                }
                for (int x = 0; x < RawInput.length(); x++)
                {
                    if (x < startparan || x > endparan)
                    {
                        AraInput += RawInput[x];
                    }
                    else if (x == startparan)
                    {
                        AraInput += IRawInput;
                    }
                }
                RawInput = AraInput;
                AraInput = L"";
            }
        }
        for (int i = 0; i < RawInput.length(); i++)
        {
            if (RawInput[i] == '*' || RawInput[i] == '/' || RawInput[i] == '!')
            {
                opin = i;
                firstopnum++;
            }
            else if (RawInput[i] == '+' || RawInput[i] == '-' && i != 0 && i != opin + 1)
            {
                opin = i;
                lastopnum++;
            }
            else if (RawInput[i] == '^' || RawInput[i] == 'v')
            {
                opin = i;
                veryfirstopnum++;
            }
        }
        for (int i = veryfirstopnum; i > 0; i--)
        {
            wstring sum = L"";
            bool squareroot = 0;
            for (int x = next; x < RawInput.length(); x++)
            {
                if (RawInput[x] == '^' || RawInput[x] == 'v')
                {
                    if(RawInput[x] == 'v'){squareroot = 1;}
                    opin = x;
                    break;
                }
            }
            for (int x = opin + 1; x < RawInput.length(); x++)
            {
                if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '^' || RawInput[x] == '-' && x != opin + 1)
                {
                    endop = x - 1;
                    break;
                }
                else if (x == RawInput.length() - 1)
                {
                    endop = x;
                    break;
                }
            }
            for (int x = opin - 1; x >= 0 && !squareroot; x--)
            {
                if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '-' && RawInput[x - 1] != '-' && x != 0)
                {
                    startop = x + 1;
                    break;
                }
                else if (x == 0)
                {
                    startop = x;
                    break;
                }
            }
            if(squareroot){startop = opin;}
            for (int x = startop; x <= endop && !squareroot; x++)
            {
                sum += RawInput[x];
            }
            for(int x = startop + 1; x <= endop && squareroot; x++)
            {
                sum += RawInput[x];
            }
            for (int x = 0; x <= RawInput.length(); x++)
            {
                if (x < startop || x > endop)
                {
                    AraInput += RawInput[x];
                }
                else if (x == startop && !squareroot)
                {
                    double a, b;
                    wstring rawx, rawy;
                    char op;
                    bool xturn = true;
                    for (int q = 0; q < sum.length(); q++)
                    {
                        if (sum[q] == '^')
                        {
                            op = sum[q];
                            xturn = false;
                        }
                        else if (xturn)
                        {
                            rawx += sum[q];
                        }
                        else
                        {
                            rawy += sum[q];
                        }
                    }
                    if (TryParse(rawx) && TryParse(rawy))
                    {
                        bool xparanted = false, yparanted = false;
                        if (rawx[0] == '0' && rawx != L"0" && rawx[1] != '.' && rawx[1] != ',')
                        {
                            xparanted = 1;
                            rawx[0] = '-';
                        }
                        if (rawy[0] == '0' && rawy != L"0" && rawy[1] != '.' && rawy[1] != ',')
                        {
                            yparanted = 1;
                            rawy[0] = '-';
                        }
                        a = stod(rawx);
                        b = stod(rawy);
                        if (b < 0)
                        {
                            if (xparanted && a < 0)
                            {
                                double sumch = a;
                                for (int z = abs(b) - 1; z > 0; z--)
                                {
                                    sumch *= a;
                                } // 2*2*2 = 2^3 = 2 times 2*=2 = 3-1times 2*=2
                                AraInput += to_wstring(1 / sumch);
                            }
                            else if (a < 0)
                            {
                                double sumch = a;
                                for (int z = abs(b) - 1; z > 0; z--)
                                {
                                    sumch *= a;
                                } // 2*2*2 = 2^3 = 2 times 2*=2 = 3-1times 2*=2
                                AraInput += to_wstring(0 - abs(1 / sumch));
                            }
                            else if (a > 0)
                            {
                                double sumch = a;
                                for (int z = b - 1; z > 0; z--)
                                {
                                    sumch *= a;
                                }
                                AraInput += to_wstring(1 / sumch);
                            }
                            else
                            {
                                RawInput = L"There\'s no power of zero(0)";
                            }
                        }
                        else if (b > 0)
                        {
                            if (xparanted && a < 0)
                            {
                                double sumch = a;
                                for (int z = b - 1; z > 0; z--)
                                {
                                    sumch *= a;
                                }
                                AraInput += to_wstring(sumch);
                            }
                            else if (a < 0)
                            {
                                double sumch = a;
                                for (int z = b - 1; z > 0; z--)
                                {
                                    sumch *= a;
                                }
                                AraInput += to_wstring(0 - abs(sumch));
                            }
                            else if (a > 0)
                            {
                                double sumch = a;
                                for (int z = b - 1; z > 0; z--)
                                {
                                    sumch *= a;
                                }
                                AraInput += to_wstring(sumch);
                            }
                            else
                            {
                                RawInput = L"There\'s no power of zero(0)";
                            }
                        }
                        else
                        {
                            AraInput += L"1";
                        }
                    }
                }
                else if(x == startop && squareroot)
                {
                    if(TryParse(sum)){AraInput += to_wstring(sqrt(stod(sum)));}
                    else{cerr << "An error occured while parsing.\n";}
                }
            }
            RawInput = AraInput;
            AraInput = L"";
            sum = L"";
            next = 0;
            endop = 0;
            startop = 0;
            opin = 0;
        }
        next = 0;
        opin = 0;

        for (int i = firstopnum; i > 0; i--)
        {
            bool facto = false;
            wstring sum = L"";
            for (int x = next; x < RawInput.length(); x++)
            {
                if (RawInput[x] == '*' || RawInput[x] == '/')
                {
                    opin = x;
                    break;
                }
                else if (RawInput[x] == '!')
                {
                    opin = x;
                    facto = 1;
                    break;
                }
            }
            for (int x = opin + 1; x < RawInput.length() && !facto; x++)
            {

                if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '-' && x != opin + 1)
                {
                    endop = x - 1;
                    break;
                }
                else if (x == RawInput.length() - 1)
                {
                    endop = x;
                    break;
                }
            }
            if (facto)
            {
                endop = opin;
            }
            for (int x = opin - 1; x >= 0; x--)
            {

                if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '-' && RawInput[x - 1] != '-' && x != 0)
                {
                    startop = x + 1;
                    break;
                }
            }
            for (int x = startop; x <= endop; x++)
            {
                sum += RawInput[x];
            }
            for (int x = 0; x <= RawInput.length(); x++)
            {
                if (x < startop || x > endop)
                {
                    AraInput += RawInput[x];
                }
                else if (x == startop)
                {
                    double a, b;
                    wstring rawx, rawy;
                    char op;
                    bool xturn = true;
                    for (int q = 0; q < sum.length() && !facto; q++)
                    {
                        if (sum[q] == '*' || sum[q] == '/')
                        {
                            op = sum[q];
                            xturn = false;
                        }
                        else if (xturn)
                        {
                            rawx += sum[q];
                        }
                        else
                        {
                            rawy += sum[q];
                        }
                    }
                    for (int q = 0; q < sum.length() - 1 && facto; q++)
                    {
                        rawx += sum[q];
                    }
                    if (TryParse(rawx) && TryParse(rawy) && !facto)
                    {
                        if (rawx[0] == '0' && rawx != L"0" && rawx[1] != '.' && rawx[1] != ',')
                        {
                            rawx[0] = '-';
                        }
                        if (rawy[0] == '0' && rawy != L"0" && rawy[1] != '.' && rawy[1] != ',')
                        {
                            rawy[0] = '-';
                        }
                        a = stod(rawx);
                        b = stod(rawy);
                        if (op == '*')
                        {
                            AraInput += to_wstring(a * b);
                        }
                        else
                        {
                            AraInput += to_wstring(a / b);
                        }
                    }
                    else if (TryParse(rawx) && facto)
                    {
                        int sumFact = stoi(rawx);
                        for (int v = sumFact - 1; v > 0; v--)
                        {
                            sumFact *= v;
                        }
                        AraInput += to_wstring(sumFact);
                    }
                }
            }
            RawInput = AraInput;
            AraInput = L"";
            sum =L"";
            next = 0;
            endop = 0;
            startop = 0;
            opin = 0;
        }
        next = 0;
        opin = 0;
        for (int i = lastopnum; i > 0; i--)
        {
            wstring sum = L"";
            for (int x = next; x < RawInput.length(); x++)
            {
                if (RawInput[x] == '+' || RawInput[x] == '-' && x != next)
                {
                    opin = x;
                    break;
                }
            }
            for (int x = opin + 1; x < RawInput.length(); x++)
            {
                if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '-' && x != opin + 1)
                {
                    endop = x - 1;
                    break;
                }
                else if (x == RawInput.length() - 1)
                {
                    endop = x;
                    break;
                }
            }
            for (int x = opin - 1; x >= 0; x--)
            {
                if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '-' && RawInput[x - 1] != '-' && x != 0)
                {
                    startop = x + 1;
                    break;
                }
            }
            for (int x = startop; x <= endop; x++)
            {
                sum += RawInput[x];
            }
            for (int x = 0; x <= RawInput.length(); x++)
            {
                if (x < startop || x > endop)
                {
                    AraInput += RawInput[x];
                }
                else if (x == startop)
                {
                    double a, b;
                    wstring rawx, rawy;
                    char op;
                    bool xturn = true;
                    for (int q = 0; q < sum.length(); q++)
                    {
                        if (sum[q] == '+' || sum[q] == '-' && q != 0 && sum[q - 1] != '-')
                        {
                            op = sum[q];
                            xturn = false;
                        }
                        else if (xturn)
                        {
                            rawx += sum[q];
                        }
                        else
                        {
                            rawy += sum[q];
                        }
                    }
                    if (TryParse(rawx) && TryParse(rawy))
                    {
                        if (rawx[0] == '0' && rawx != L"0" && rawx[1] != '.' && rawx[1] != ',')
                        {
                            rawx[0] = '-';
                        }
                        if (rawy[0] == '0' && rawy != L"0" && rawy[1] != '.' && rawy[1] != ',')
                        {
                            rawy[0] = '-';
                        }
                        a = stod(rawx);
                        b = stod(rawy);
                        if (op == '+')
                        {
                            AraInput += to_wstring(a + b);
                        }
                        else
                        {
                            AraInput += to_wstring(a - b);
                        }
                    }
                }
            }
            RawInput = AraInput;
            AraInput = L"";
            sum = L"";
            next = 0;
            endop = 0;
            startop = 0;
            opin = 0;
        }
        wcout << "\n\n"
             << RawInput << "\n\n";
    }

    return 0;
}

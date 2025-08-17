#ifndef ORENO_H
#define ORENO_H
#include <QApplication>
std::string clean_white_space(std::string a);
std::wstring clean_white_space(std::wstring a);
void clean_null(std::string a);
bool TryParse(std::string rawx);
bool TryParse(std::wstring rawx);
bool TryParse(QString rawx);
#endif

#include "Defs.hpp"

void				Contact::AddFirstName(const std::string& str) {FirstName = str; };
void				Contact::AddLastName(const std::string& str) {LastName = str; };
void				Contact::AddPhoneNumber(const std::string& str) {PhoneNumber = str; };
void				Contact::AddNickName(const std::string& str) {NickName = str; };
void				Contact::AddSecret(const std::string& str) {Secret =  str; };
std::string			Contact::GetFirstName()	{return FirstName; };
std::string			Contact::GetLastName()	{return LastName; };
std::string			Contact::GetNickName()	{return NickName; };
std::string			Contact::GetPhoneNumber()	{return PhoneNumber; }
std::string			Contact::GetSecret()	{return Secret; }

#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

int main() {
	char from_name[60];
	char to_name[60];
  char holiday[60];
  char message[60];
  int max_length = 60;
  
  /* Time info */
  time_t raw_time;
  struct tm * time_info;
  char time_buffer[60];

  time(&raw_time);
  time_info = localtime(&raw_time);
  strftime(time_buffer, 60, "%m/%d/%Y", time_info);

	cout << "From > ";
	cin.getline(from_name, 60);

	cout << "To > ";
	cin.getline(to_name, 60);

	cout << "Holiday? > ";
	cin.getline(holiday, 60);

	cout << "Message? > ";
	cin.getline(message, 60);

	cout << "/";
	for (size_t i = 0; i < max_length; i++) {
		cout << "¯";
  }
	cout << "\\" << endl;

	cout << "| From: " << from_name;
  for (int i = 0; i < max_length - strlen(from_name) - 18; i++) {
    cout << " ";
  }
  cout << time_buffer << " " << "|" << endl;

	cout << "|";
	for (size_t i = 0; i < max_length; i++)
		cout << "-";
	cout << "|" << endl;

	cout << "| Dear " << to_name << ",";
  for (int i = 0; i < max_length - strlen(holiday) - 6; i++) {
    cout << " ";
  }
	cout << "|" << endl;

	cout << "|";
  for (int i = 0; i < max_length; i++) {
    cout << " ";
  }
	cout << "|" << endl;

	cout << "| Happy " << holiday << "!";
  for (int i = 0; i < max_length - strlen(holiday) - 8; i++) {
    cout << " ";
  }
	cout << "|" << endl;

  cout << "| " << message;
  for (int i = 0; i < max_length - strlen(message) - 1; i++) {
    cout << " ";
  }
	cout << "|" << endl;

	cout << "\\";
	for (size_t i = 0; i < max_length; i++)
		cout << "_";
	cout << "/" << endl;

	return 0;
}
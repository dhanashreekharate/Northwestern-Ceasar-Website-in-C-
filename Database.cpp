#include "stdafx.h"
#include <Windows.h>
#include "mysql.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <ctime>
#pragma warning(disable : 4996) 
using namespace std;


MYSQL *conn;

int main(int argc, char *argv[])
{
	conn = mysql_init(NULL);
	mysql_real_connect(
		conn,
		"localhost",
		"root", //change to whatever your default username is
		"root", //change to whatever your default password is
		"project3-nudb",
		0, //whatever port you choose
		NULL,
		CLIENT_MULTI_RESULTS);

	MYSQL_RES *res_set;
	MYSQL_RES *res_set_1;
	MYSQL_ROW row, row_1;
	MYSQL_RES *res_set_2;
	MYSQL_ROW row_2;
	time_t timer;
	tm * time;
	std::string month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	const int BASE_YEAR = 1900;
	std::time(&timer);
	time = localtime(&timer);
	string query3 = "select UoSCode from uosoffering where year =";

	mysql_query(conn, "SELECT Name,Password,ID FROM Student;");
	res_set = mysql_store_result(conn);
	int numrows = (int)mysql_num_rows(res_set);

	string usrName, usrPwd;
	cout << "Please input your username:" << endl;
	getline(cin, usrName);
	for (int i = 0; i < numrows; i++)
	{   
		if (i == numrows - 1)
		{cout << "User not found,Please enter correct Username" << endl;}
		row = mysql_fetch_row(res_set);
		if else(row != NULL)
		{
			if (usrName == row[0])
			{
				cout << "Please input your password:" << endl;
				getline(cin, usrPwd);
				if (usrPwd == row[1])
				{
					cout << "You've logged in successfully" << endl;
					cout << "The courses for this quarter are" << endl;

					if (int(time->tm_year + BASE_YEAR) == 2017)

					{
						if (month[time->tm_mon] == "Dec" || month[time->tm_mon] == "Jan" || month[time->tm_mon] == "Feb")

						{
							query3 += (time->tm_year + BASE_YEAR);
							query3 += " \" ";
							query3 += "semester=";
							query3 += "Q2";
							query3 += " \"";
							query3 += " \;";
							mysql_query(conn, query3.c_str());
							res_set_2 = mysql_store_result(conn);
							int numrows_2 = (int)mysql_num_rows(res_set_2);
							for (int k = 0; k < numrows_2; k++)
							{
								row_2 = mysql_fetch_row(res_set_2);
								if (row_2 != NULL)
								{
									cout << row_2[0] << endl;
								}
							}
						}


					}

					else if (int(time->tm_year + BASE_YEAR) == 2017)

					{
						if (month[time->tm_mon] == "Sep" || month[time->tm_mon] == "Oct" || month[time->tm_mon] == " Nov" || month[time->tm_mon] == "Dec")

						{

							query3 += (time->tm_year + BASE_YEAR);
							query3 += " \" ";
							query3 += "semester=";
							query3 += "Q1";
							query3 += " \"";
							query3 += " \;";
							mysql_query(conn, query3.c_str());
							res_set_2 = mysql_store_result(conn);
							int numrows_2 = (int)mysql_num_rows(res_set_2);
							for (int k = 0; k < numrows_2; k++)
							{
								row_2 = mysql_fetch_row(res_set_2);
								if (row_2 != NULL)
								{
									cout << row_2[0] << endl;
								}
							}
						}

					}

						else if (int(time->tm_year + BASE_YEAR) == 2018)

						{
							if (month[time->tm_mon] == "Mar" || month[time->tm_mon] == "Apr" || month[time->tm_mon] == "May")

							{

								query3 += (time->tm_year + BASE_YEAR);
								query3 += " \" ";
								query3 += "semester=";
								query3 += "Q3";
								query3 += " \"";
								query3 += " \;";
								mysql_query(conn, query3.c_str());
								res_set_2 = mysql_store_result(conn);
								int numrows_2 = (int)mysql_num_rows(res_set_2);
								for (int k = 0; k < numrows_2; k++)
								{
									row_2 = mysql_fetch_row(res_set_2);
									if (row_2 != NULL)
									{
										cout << row_2[0] << endl;
									}
								}
							}
						}

						else if (int(time->tm_year + BASE_YEAR) == 2018)
						{
							if (month[time->tm_mon] == "Jun" || month[time->tm_mon] == "Jul" || month[time->tm_mon] == "Aug")

							{

								query3 += (time->tm_year + BASE_YEAR);
								query3 += " \"";
								query3 += "semester=";
								query3 += "Q4";
								query3 += " \"";
								query3 += " \;";
								mysql_query(conn, query3.c_str());
								res_set_2 = mysql_store_result(conn);
								int numrows_2 = (int)mysql_num_rows(res_set_2);
								for (int k = 0; k < numrows_2; k++)
								{
									row_2 = mysql_fetch_row(res_set_2);
									if (row_2 != NULL)
									{
										cout << row_2[0] << endl;
									}
								}
							}
						}

						/*res_set_2 = mysql_store_result(conn);
						int numrows_2 = (int)mysql_num_rows(res_set_2);
						for (int k = 0; k < numrows_2; k++)
						{
							row_2 = mysql_fetch_row(res_set_2);
							if (row_2 != NULL)
							{
								cout << row_2[0] << endl;
							}
						}*/
						int menuNumber;
						cout << "The following options are";
						cout << "\n\n";
						cout << "2. Transcripts\n";
						cout << "3. Enroll\n";
						cout << "4. Withdraw\n";
						cout << "5. Personal Details\n";
						cout << "6. Logout\n";
						cout << "Please enter a value between 2 to 6 to go to the respective menu: ";
						cin >> menuNumber;


						if (menuNumber == 2) {
							string query1 = "select t.UoSCode from student s, transcript t where s.ID = t.StudId and s.ID = ";
							query1 += row[2];
							query1 += " \; ";

							mysql_query(conn, query1.c_str());
							res_set_1 = mysql_store_result(conn);
							int numrows_1 = (int)mysql_num_rows(res_set_1);
							for (int j = 0; j < numrows_1; j++)
							{
								row_1 = mysql_fetch_row(res_set_1);
								if (row_1 != NULL)
								{
									cout << row_1[0] << endl;
								}
							}
						}
					}
				
				string courseDetailedInfo;
				cout << "Please choose the course you would like to show detailed information:" << endl;
				getline(cin, courseDetailedInfo);
				MYSQL_RES *res_set_3;
				MYSQL_ROW row_2;
				string query2 = " select u.UoSCode, u.UoSName,t.Year, t.Semester, c.Enrollment, c.MaxEnrollment, c.InstructorId, f.Name , t.grade from transcript t, student s, unitofstudy u, uosoffering c, faculty f where s.ID = t.StudId and t.UoSCode = u.UoSCode and  c.UoSCode = u.UoSCode and t.Year = c.Year and t.Semester = c.Semester and f.Id = c.InstructorId and s.ID = ";
				query2 += row[2];
				query2 += " and t.UoSCode = \"";
				query2 += courseDetailedInfo;
				query2 += "\";";
				//cout<<query2<<endl;
				mysql_query(conn, query2.c_str());
				res_set_3 = mysql_store_result(conn);
				//int numrows_2 = (int)mysql_num_rows(res_set_2);
				row_2 = mysql_fetch_row(res_set_3);
				if (row_2 != NULL)
				{
					for (int k = 1; k < 8; k++)
					{
						cout << row_2[k] << endl;
					}
				}
				else
				{
					cout << "Wrong Course Number, please check it again." << endl;
				}
				break;
			}
		}

			else { cout << "You input a wrong password" << endl; break; }
		}

		
		
	
}
		mysql_free_result(res_set);
		mysql_close(conn);
		return 0;

	
	}


#include <iostream>
using namespace std;

int arr[4][4] = { 0 };
int x, y, winner;
bool nexttype;//true for X, false for O;
int testend()
{
	int a;
	for (a = 1; a <= 3;a++)//horizontal test
	{
		if (arr[a][1]==arr[a][2] && arr[a][1]==arr[a][3] && arr[a][2]==arr[a][3])
		{	
			winner = arr[a][1];
			return arr[a][1];
		}
	}//horizontal test
	for (a = 1; a <= 3; a++)//vertical test
	{
		if (arr[1][a] == arr[2][a] && arr[1][a] == arr[3][a] && arr[2][a] == arr[3][a])
		{
			winner = arr[1][a];
			return arr[1][a];
		}
	}//vertical test
	
	if (arr[1][1]==arr[2][2] && arr[1][1]==arr[3][3] && arr[2][2]==arr[3][3])
	{
		winner = arr[1][1];
		return arr[1][1];
	}//diagonal test
	if (arr[1][3] == arr[2][2] && arr[1][3] == arr[3][1] && arr[2][2] == arr[3][1])
	{
		winner = arr[1][3];
		return arr[1][3];
	}//diagonal test
	return 0;//not finish
}
void paintbg()
{
	int i, j;
	for (j = 1; j <= 6;j++)
	{
		if (j % 2 == 0) cout << static_cast <int>(j/2);//write col number

		for (i = 1; i <= 12; i++)
		{
			if (j==1)//handle the first row
			{
				if ((i+1)%4==0)//write row number
				{
					cout << static_cast <int> ((i+1)/4);
				}//end if i%3
				else
				{
					cout << " ";
				}//end if i%3
			} // end if j==1
			else
			{
				if ((j+1)%2 ==0)//for a row all with -----
				{
					if (i!=1)
					{
						if (i==5 || i==9)
						{
							cout << "+";
						} 
						else
						{
							cout << "-";
						}
					} 
					else
					{
						cout << " ";
					}
					
				}//(j+1)%2 ==0 
				else
				{
					if (i==4 || i==8)
					{
						cout << "|";
					} 
					else
					{
						//key place
						if ((j%2==0) && ((i+2)%4==0))
						{
							if (arr[j / 2][(i + 2) / 4] == 0)
							{
								cout << " ";
							}
							if (arr[j / 2][(i + 2) / 4] == 1)
							{
								cout << "X";
							}
							if (arr[j / 2][(i + 2) / 4] == 2)
							{
								cout << "O";
							}
						} 
						else
						{
							cout << " ";
						}

					}
					
				}//(j+1)%2 ==0
				
			}// end if j==1
			

		}// for i
		

		cout << endl;
	}//for j

}//end of function
void inputdata()
{

	do //test this position whether it has already have number
	{
		if (nexttype == true)
		{
			cout << "Player X: Input the row position." << endl;
		}
		else
		{
			cout << "Player O: Input the row position." << endl;
		}
		cin >> y;
		while (y > 3 || y <= 0 || cin.fail())
		{
			cout << "Wrong row position. Input row position again." << endl;
			cin.clear();
			cin.sync();
			cin >> y;
		}
		if (nexttype == true)
		{
			cout << "Player X: Input the column position." << endl;
		}
		else
		{
			cout << "Player O: Input the column position." << endl;
		}
		cin >> x;
		while (x > 3 || x <= 0 || cin.fail())
		{
			cout << "Wrong column position. Input column position again." << endl;
			cin.clear();
			cin.sync();
			cin >> x;
		}
		if (arr[y][x]!=0)
		{
			cout << "This position has been already occupied. Input again." << endl;
		}
	} while (arr[y][x]!=0);//test this position whether it has already have number
	

	if (nexttype == true)
	{
		arr[y][x] = 1;
		nexttype = !nexttype;
	}
	else
	{
		arr[y][x] = 2;
		nexttype = !nexttype;
	}
	system("cls");
	paintbg();
	cout << endl;
	testend();
}
void main()
{
	paintbg();
	cout << "Who go first? 1 is for X go first, 2 is for O go first." << endl;
	int temp;
	cin>>temp;
	while (cin.fail() || temp>2 || temp<=0)
	{
		cout << "Wrong input data. Input again."<<endl;
		cin.clear();
		cin.sync();
		cin >> temp;

	}
	if (temp==1)
	{
		nexttype = true;//X go first
	} 
	else
	{
		nexttype = false;//O go first
	}
	
	while (testend()==0)
	{
		inputdata();
	}
	if (winner==1)
	{
		cout << "Winner is X" << endl;
	} 
	else
	{
		cout << "Winner is O" << endl;
	}
}
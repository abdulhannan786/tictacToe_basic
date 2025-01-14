#include<iostream>

// #define ENABLEDEBUGGING

using namespace std;

char Board[3][3] = {{'0','1','2'},{'3','4','5'},{'9','7','8'}};
bool gamestat = true;
bool player = 0;
int plr1Choise[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
int plr2Choise[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1}; 

void printBoard(char Board[3][3])
{
    cout<<endl<<"-------------"<<endl;
    for(int i=0; i<3;i++)
    {
        cout<<"|";
        for (int j = 0; j < 3; j++)
        {
            cout<<" "<<Board[i][j]<<" ";
            cout<<"|";
        }
        cout<<endl<<"-------------"<<endl;

    }
}

void printInfo()
{
    cout<<"first will be O and than X only type the block name only "<<endl;
    cout<<"---------------------------------------------------------"<<endl<<endl;
}

void printArrya(int prntArray[],int size)
{
   
    for (int i = 0; i < size; i++)
    {
        cout<<prntArray[i]<<"\t";
    }
    cout<<endl;
}

bool appendChoice(int arr[], int size, int data)
{
    int i = 0;
    // Traverse the array to find the first empty slot
    while (i < size && arr[i] != -1)
    {
        i++;
    }
    // Check if there's space to add the new data
    if (i < size)
    {
        arr[i] = data;
        return true; // Data appended successfully
    }
    else
    {
        return false; // No space left in the array
    }
}
bool ArraySearch(int Array[], int sizeArray, int key[], int sizeKey) {
    // Iterate through all elements of the key[] array
    for (int i = 0; i < sizeKey; i++) {
        bool found = false;

        // Search for key[i] in the Array
        for (int j = 0; j < sizeArray; j++) {
            if (key[i] == Array[j]) {
                found = true;
                break; // No need to search further for this key
            }
        }

        // If a key is not found, return false immediately
        if (!found) {
            //cout << "Key " << key[i] << " not found in Array." << endl;
            return false;
        }
    }

    // If all keys are found, return true
    //cout << "All keys found in Array. It is a subset." << endl;
    return true;
}
void winner()
{
    if(player)
    {
        cout<<"player 1 won"<<endl;
    }
    else
    {
        cout<<"player 2 won"<<endl;
    }
}
int checkforWin(int choiseary[], int choise)
{
    int row = choise/3;
    //cout<<"ROW NUMBER: "<<row<<endl;
    // Arrcurr = player = 0? plr1Choise: plr2Choise;
    if(row == 0)
    {
        int chck[] = {choise+3,choise+6};
        int checkRow[] = {0,1,2};
        int checkdiagn[] = {0,1,2};
        if(ArraySearch(choiseary,8,chck,2) || ArraySearch(choiseary,8,checkRow,3))
        {
            //cout<<"horizontal found"<<endl;
            winner();
            gamestat = false;
            return 0;
        }   
    }
    
    if(row == 1)
    {
        int chck[] = {choise-3,choise+3};
        int checkRow[] = {3,4,5};
        if(ArraySearch(choiseary,8,chck,2) || ArraySearch(choiseary,8,checkRow,3))
        {
            //cout<<"horizontal found"<<endl;
            winner();
            gamestat = false;
            return 0; 
        }   
    }
    if(row == 2)
    {
        int chck[] = {choise-6,choise-3};
        int checkRow[] = {6,7,8};
        if(ArraySearch(choiseary,8,chck,2) || ArraySearch(choiseary,8,checkRow,3))
        {
            //cout<<"horizontal found"<<endl;
            winner();
            gamestat = false;
            return 0;   
        }
    }    
    return -1;
}


bool updateBoard(char Board[3][3], int input,bool player)
{
        int temp = input;
        int row = temp/3;
        int col = temp%3;    
#ifdef ENABLEDEBUGGING
cerr<<"row : "<<temp/3<<" column :"<<temp%3<<"at loc: "<<Board[row][col]<<endl;
#endif        
        
        if((Board[row][col] != 'O') && (Board[row][col] != 'X'))
        {
            if(!player)
            {
                Board[temp/3][temp%3] = 'O';
                appendChoice(plr1Choise,8,input);
                printArrya(plr1Choise,8);
#ifdef ENABLEDEBUGGING                
cout<<"Board Updated for Move(1) : "<<input<<endl;
#endif                
            }
            else
            {
                Board[temp/3][temp%3] = 'X';
                appendChoice(plr2Choise,8,input);
                printArrya(plr2Choise,8);
#ifdef ENABLEDEBUGGING
cout<<"Board Updated for Move(2) : "<<input<<endl;
#endif
            }
            printBoard(Board);
            return 1;
        }
        else
        {
            cout<<"Move Already Played"<<endl;
            return 0;
        }      
}

int main()
{
    printBoard(Board);
    printInfo();

    int input = 0;
// function updateBoard(Board,Option,Player);

    while (gamestat)
    {
        cout<<"player:"<<(player? "2" : "1 ")<<"enter your choise :";
        cin>>input;
        cout<<endl;
        if(input<9 && input>=0)
        {
        if(updateBoard(Board,input,player))
        {
            player = !player;
            // continue;
        }
         
        }
        else
        {
            cout<<"invalid input "<<endl;
        }
        checkforWin(plr1Choise,input);
        checkforWin(plr2Choise,input);
    }
    
    return 0;
}
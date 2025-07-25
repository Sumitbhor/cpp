#include <iostream>
#include <string>
#include <mysql.h>

using namespace std ;

class dbmanager
{
private:
    MYSQL *conn=NULL;
public:
    dbmanager(){
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        cerr<<"mysql_init() failed\n";
        exit(EXIT_FAILURE);
    }
    if (mysql_real_connect(conn, "localhost","root", "root123","assessmentdb",0,NULL,0 )==NULL)
    {
        cerr<<"mysql real connect failed\n";
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }
    
    }
    ~dbmanager()
    {
         mysql_close(conn);
    }

void displayquestions(){
    MYSQL_RES *res ;
    MYSQL_ROW row ;

    if (mysql_query(conn,"SELECT * FROM questionbank"))
        {
            cerr<<" SELECT * FROM assessmentdb.questionbank failed .Error "<< mysql_error(conn)<<"\n";
        }

     res = mysql_store_result(conn);
    if (res == NULL) 
        {
            cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << "\n";
            return;
        }
    while ((row = mysql_fetch_row(res))!= NULL)
        {
           cout << "\n\nID: " << row[0]
                << "\nSubject ID: " << row[1]
                << "\nTitle: " << row[2]
                << "\nA: " << row[3]
                << "\n B: " << row[4]
                << "\n C: " << row[5]
                << "\n D: " << row[6]
                << "\nAnswer Key: " << row[7]
                << "\n Evaluation Criteria ID: " << row[8] <<endl;

        }
     mysql_free_result(res);
    }
bool insertquestions( int id ,int subjectid , string& title, string& a , string& b, string& c, string& d , string& answerkey, int evaluationcriteriaid)
    {
        char query[512];
        sprintf(query, "INSERT INTO questionbank ( id ,subjectid, title, a, b, c, d, answerkey, evaluationcriteriaid) VALUES (%d ,%d, '%s', '%s', '%s', '%s', '%s', '%s', %d)",
         id ,subjectid, title.c_str(), a.c_str(), b.c_str(), c.c_str(), d.c_str(), answerkey.c_str(), evaluationcriteriaid);

        if (mysql_query(conn, query))
        {
            cerr << "Insert query failed. Error: " << mysql_error(conn) << "\n";
            return false;
        }
        return true;
}

bool update(int id,
            int subjectid , 
            string& title, 
            string& a , 
            string& b, 
            string& c, 
            string& d , 
            string& answerkey, 
            int evaluationcriteriaid)
    {
      char query[512];
      snprintf(query,sizeof(query), "UPDATE questionbank SET id=%d, subjectid=%d, title='%s', a='%s', b='%s', c='%s', d='%s', answerkey='%s', evaluationcriteriaid=%d WHERE id=%d",
              id, subjectid, title.c_str(), a.c_str(), b.c_str(), c.c_str(), d.c_str(), answerkey.c_str(), evaluationcriteriaid, id);
        if (mysql_query(conn, query))
        {
            cerr << "Update query failed. Error: " << mysql_error(conn) << "\n";
            return false;
        }
        return true;

    }
    void deletequestion(int id)
    {
        char query[256];
        sprintf(query, "DELETE FROM questionbank WHERE id=%d", id);
        if (mysql_query(conn, query))
        {
            cerr << "Delete query failed. Error: " << mysql_error(conn) << "\n";
        }
    }
    void specificquestion(int id)
    {
        char query[256];
        sprintf(query, "SELECT * FROM questionbank WHERE id=%d", id);
        if (mysql_query(conn, query))
        {
            cerr << "Select specific question query failed. Error: " << mysql_error(conn) << "\n";
            return;
        }

        MYSQL_RES *res = mysql_store_result(conn);
        if (res == NULL)
        {
            cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << "\n";
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(res);
        if (row != NULL)
        {
            cout << "\n\nID: " << row[0]
                 << "\nSubject ID: " << row[1]
                 << "\nTitle: " << row[2]
                 << "\nA: " << row[3]
                 << "\nB: " << row[4]
                 << "\nC: " << row[5]
                 << "\nD: " << row[6]
                 << "\nAnswer Key: " << row[7]
                 << "\nEvaluation Criteria ID: " << row[8] << endl;
        }
        else
        {
            cout << "No question found with ID: " << id << endl;
        }

        mysql_free_result(res);
    }


};
void displaymenu(){
    cout<<"\n1. Insert Question\n";
    cout<<"2. Display Questions\n";
    cout<<"3. Update Question\n";
    cout<<"4. Delete Question\n";
    cout<<"5.display specific question \n";
    cout<<"6. Exit\n";
}

int main()
{
    dbmanager *ptrdbmanager=NULL;
    ptrdbmanager = new dbmanager();
    int choice=0; 
    while(1)
    {
        cout<<"==========================";
        cout<<"enter your choice";
        displaymenu();
        cin>>choice;


        switch (choice) 
        {

        case 1:
            {
                int id, subjectid, evaluationcriteriaid;
                string title, a, b, c, d, answerkey;

                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Subject ID: ";
                cin >> subjectid;
                cout << "Enter Question Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Option A: ";
                cin.ignore();
                getline(cin, a);
                cout << "Enter Option B: ";
                cin.ignore();
                getline(cin, b);
                cout << "Enter Option C: ";
                cin.ignore();
                getline(cin, c);
                cout << "Enter Option D: ";
                cin.ignore();
                getline(cin, d);
                cout << "Enter Answer Key: ";
                cin.ignore();
                getline(cin, answerkey);
                cout << "Enter Evaluation Criteria ID: ";
                cin >> evaluationcriteriaid;

                ptrdbmanager->insertquestions(id, subjectid, title, a, b, c, d, answerkey, evaluationcriteriaid);
            }
            break;
        case 2:
            ptrdbmanager->displayquestions();
            break;
        case 3:
            {
                int id, subjectid, evaluationcriteriaid;
                string title, a, b, c, d, answerkey;

                cout << "Enter ID of the question to update: ";
                cin >> id;
                cout << "Enter New Subject ID: ";
                cin >> subjectid;
                cout << "Enter New Question Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter New Option A: ";
                cin.ignore();
                getline(cin, a);
                cout << "Enter New Option B: ";
                cin.ignore();
                getline(cin, b);
                cout << "Enter New Option C: ";
                cin.ignore();
                getline(cin, c);
                cout << "Enter New Option D: ";
                cin.ignore();
                getline(cin, d);
                cout << "Enter New Answer Key: ";
                cin.ignore();
                getline(cin, answerkey);
                cout << "Enter New Evaluation Criteria ID: ";
                cin >> evaluationcriteriaid;

                ptrdbmanager->update(id, subjectid, title, a, b, c, d, answerkey, evaluationcriteriaid);
            }
            break;
        case 4:
            {
                int id;
                cout << "Enter ID of the question to delete: ";
                cin >> id;
                ptrdbmanager->deletequestion(id);
            }
            break;  
        case 5:
            {
                int id;
                cout << "Enter ID of the specific question to display: ";
                cin >> id;
                ptrdbmanager->specificquestion(id);
            }
            break;
        
        case 6:
            delete ptrdbmanager;
            cout << "Exiting the program.\n";
            return 0;
        }
    }
}


//g++ questionbank.cpp -o db.exe -I "C:\Program Files\MySQL\MySQL Server 8.0\include" -L "C:\Program Files\MySQL\MySQL Server 8.0\lib" -lmysql

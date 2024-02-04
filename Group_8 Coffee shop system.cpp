#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

string int_to_string(int user_input)
{
    string word;

    stringstream ss;
    ss << user_input;
    ss >> word;

    return word;
}

int string_to_int(string user_input)
{
    int number;

    stringstream ss;
    ss << user_input;
    ss >> number;

    return number;
}

bool int_validation(string user_input, bool allow_nagetive, bool check_range, string min_range = "0", string max_range = "0")
{
    bool verify = true;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < user_input.length(); i++)
    {
        if (!isdigit(user_input[i]))
        {
            verify = false;
            count1++;
        }
        if (user_input[i] == '-')
        {
            count2++;
        }
    }

    if (user_input[0] == '-' && count1 == 1 && count2 == 1 && allow_nagetive)
    {
        verify = true;
    }

    if (check_range && verify)
    {
        long int number1 = string_to_int(user_input), number2 = string_to_int(min_range), number3 = string_to_int(max_range);

        if (number1 < number2 || number1 > number3)
        {
            verify = false;
        }
    }

    return verify;
}

bool float_validation(string user_input, bool allow_nagetive)
{
    bool verify = true;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < user_input.length(); i++)
    {
        if (!isdigit(user_input[i]))
        {
            verify = false;
            count3++;
        }
        if (user_input[i] == '-')
        {
            count1++;
        }
        if (user_input[i] == '.')
        {
            count2++;
        }
    }

    if (user_input[0] == '-' && count2 == 0 && count1 == 1 && allow_nagetive && count3 == 1 && user_input.length() > 1)
    {
        verify = true;
    }

    if (count2 == 1 && count1 == 0 && count3 == 1 && user_input.length() > 1)
    {
        verify = true;
    }

    if (user_input[0] == '-' && count2 == 1 && count1 == 1 && allow_nagetive && count3 == 2 && user_input.length() > 2)
    {
        verify = true;
    }

    return verify;
}

bool email_validation(string user_input)
{
    bool verify = false;
    int At_sign, dot;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < user_input.length(); i++)
    {
        if (user_input[i] == '@')
        {
            At_sign = i;
            count1++;
        }
        if (user_input[i] == '.')
        {
            dot = i;
            count2++;
        }
        if (user_input[i] == ' ')
        {
            count3++;
        }
    }

    if (count1 == 1 && count2 == 1 && At_sign < dot && count3 == 0)
    {
        verify = true;
    }

    return verify;
}

bool no_space_only_validation(string user_input)
{
    bool verify = true;

    for (int i = 0; i < user_input.length(); i++)
    {
        if (user_input[i] == ' ')
        {
            verify = false;
        }
    }

    return verify;
}

bool no_null_validation(string user_input)
{
    bool verify = true;

    if (user_input.length() == 0)
    {
        verify = false;
    }

    return verify;
}

bool alpha_number_validation(string user_input)
{
    bool verify = true;

    for (int i = 0; i < user_input.length(); i++)
    {
        if (!isalnum(user_input[i]))
        {
            verify = false;
        }
    }

    return verify;
}

bool alpha_with_space_validation(string user_input)
{
    bool verify = true;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < user_input.length(); i++)
    {
        if (!isalpha(user_input[i]))
        {
            verify = false;
            count1++;
        }
        if (user_input[i] == ' ')
        {
            count2++;
        }
    }

    if (count1 == count2)
    {
        verify = true;
    }

    return verify;
}

bool IC_validation(string user_input)
{
    bool verify = false;

    if (user_input.length() == 14)
    {
        if (isdigit(user_input[0]) && isdigit(user_input[1]) && isdigit(user_input[2]) && isdigit(user_input[3]) && isdigit(user_input[4]) && isdigit(user_input[5]) && user_input[6] == '-' && isdigit(user_input[7]) && isdigit(user_input[8]) && user_input[9] == '-' && isdigit(user_input[10]) && isdigit(user_input[11]) && isdigit(user_input[12]) && isdigit(user_input[13]))
        {
            verify = true;
        }
    }

    return verify;
}

string space_to_underscore(string user_input)
{
    for (int i = 0; i < user_input.length(); i++)
    {
        if (user_input[i] == ' ')
        {
            user_input[i] = '_';
        }
    }

    return user_input;
}

string underscore_to_space(string user_input)
{
    for (int i = 0; i < user_input.length(); i++)
    {
        if (user_input[i] == '_')
        {
            user_input[i] = ' ';
        }
    }

    return user_input;
}

string float_to_string(float user_input)
{
    string word;

    stringstream ss;
    ss << user_input;
    ss >> word;

    return word;
}

float string_to_float(string user_input)
{
    float number;

    stringstream ss;
    ss << user_input;
    ss >> number;

    return number;
}

struct admin_struct
{
    int index;
    string name;
    string username;
    string password;
};

struct admin_node
{
    admin_struct data;
    admin_node *next;
};

class admin_queue
{
private:
    admin_node *front, *rear;
    admin_node *hashTable[10];

public:
    admin_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(admin_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new admin_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new admin_node;
            front->data = node;
            front->next = NULL;
        }
    }
    admin_struct serve()
    {
        admin_struct node;
        if (!isEmpty())
        {
            node = front->data;
            admin_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        admin_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    admin_struct get_data_by_index(int index)
    {
        admin_node *temp = front;
        admin_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    void edit_by_index(int index, admin_struct edited_data)
    {
        admin_node *temp = front;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            temp->data = edited_data;
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "Edit Error. Data Not found.";
        }
    }
    void delete_by_index(int index)
    {
        admin_node *temp = front;
        admin_node *prev = temp;

        while (temp != NULL && temp->data.index != index)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
            prev = NULL;
            delete prev;
        }
        else
        {
            cout << "Delete Error. Data Not found.";
        }
    }
    admin_node *get_front_pointer()
    {
        return front;
    }
    int compare(const admin_struct &a, const admin_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else if (sort == 2)
        {
            // Descending order based on index
            return b.index - a.index;
        }
        else if (sort == 3)
        {
            // Ascending order based on name
            return a.name.compare(b.name);
        }
        else if (sort == 4)
        {
            // Descending order based on name
            return b.name.compare(a.name);
        }
        else if (sort == 5)
        {
            // Ascending order based on username
            return a.username.compare(b.username);
        }
        else if (sort == 6)
        {
            // Descending order based on username
            return b.username.compare(a.username);
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }

    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                admin_node *sorted = NULL;
                admin_node *current = front;

                while (current != NULL)
                {
                    admin_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    admin_node *prevSorted = NULL;
                    admin_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            admin_node *current = hashTable[i];
            while (current != NULL)
            {
                admin_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        admin_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = current->data.name;
            }
            else if (type == 2)
            {
                key = current->data.username;
            }

            int hashIndex = calculateHashIndex(key);

            admin_node *newNode = new admin_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                admin_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }

    admin_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        admin_node *resultList = NULL;
        admin_node *resultListTail = NULL;

        admin_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.name == keyword)
                {
                    admin_node *newNode = new admin_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 2)
            {
                if (current->data.username == keyword)
                {
                    admin_node *newNode = new admin_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
    }
};

class admins
{
    admin_queue admin;

public:
    admins()
    {
        init();
    }

    ~admins()
    {
        store_to_file();
    }

    void init()
    {
        fstream admins_file;
        admins_file.open("admins.txt", ios::in);

        admin_struct c;
        int i = 1;

        while (admins_file >> c.name >> c.username >> c.password)
        {
            c.index = i;
            c.name = underscore_to_space(c.name);
            c.username = underscore_to_space(c.username);
            c.password = underscore_to_space(c.password);
            admin.append(c);
            i++;
        }
        admins_file.close();
    }

    void store_to_file()
    {
        admin.insertionSort(1);
        fstream admins_file;
        admins_file.open("admins.txt", ios::out);

        while (!admin.isEmpty())
        {
            admin_struct c = admin.serve();

            c.name = space_to_underscore(c.name);
            c.username = space_to_underscore(c.username);
            c.password = space_to_underscore(c.password);
            admins_file << c.name << " " << c.username << " " << c.password << endl;
        }
        admins_file.close();
    }

    void create_admin()
    {
        admin_struct new_admin;

        cout << "Enter admin Name : ";
        fflush(stdin);
        getline(cin, new_admin.name);
        while (!no_null_validation(new_admin.name))
        {
            fflush(stdin);
            cout << "Name should not be empty, Please re-enter admin Name : ";
            getline(cin, new_admin.name);
        }

        string name_upper_case;
        for (int i = 0; i < new_admin.name.length(); i++)
        {
            name_upper_case += toupper(new_admin.name[i]);
        }
        new_admin.name = name_upper_case;

        cout << "Enter admin Username : ";
        fflush(stdin);
        getline(cin, new_admin.username);

        bool not_unique = false;
        admin.init_hashtable(2);
        admin_node *temp_check_unique = admin.hashing_search(2, new_admin.username);
        if (temp_check_unique != NULL)
        {
            not_unique = true;
        }

        while (!no_null_validation(new_admin.username) || !alpha_number_validation(new_admin.username) || not_unique)
        {
            if (!no_null_validation(new_admin.username))
            {
                cout << "Username should not be empty, Please re-enter the Username : ";
                fflush(stdin);
                getline(cin, new_admin.username);
            }
            else
            {
                if (!no_space_only_validation(new_admin.username))
                {
                    cout << "Invalid input, Please re-enter the Username : ";
                    fflush(stdin);
                    getline(cin, new_admin.username);
                }
                else
                {
                    if (not_unique)
                    {
                        cout << "The Username has been used, Please re-enter the Username : ";
                        fflush(stdin);
                        getline(cin, new_admin.username);
                    }
                }
            }
            not_unique = false;

            admin.init_hashtable(2);
            temp_check_unique = admin.hashing_search(2, new_admin.username);
            if (temp_check_unique != NULL)
            {
                not_unique = true;
            }
        }

        cout << "Enter admin password : ";
        fflush(stdin);
        getline(cin, new_admin.password);
        while (!no_null_validation(new_admin.password) || !no_space_only_validation(new_admin.password))
        {
            if (!no_null_validation(new_admin.password))
            {
                fflush(stdin);
                cout << "Password should not be empty, Please re-enter the Password : ";
                getline(cin, new_admin.password);
            }
            else
            {
                if (!no_space_only_validation(new_admin.password))
                {
                    fflush(stdin);
                    cout << "Cannot content space in input, Please re-enter the Password : ";
                    getline(cin, new_admin.password);
                }
            }
        }

        new_admin.index = admin.get_total_item() + 1;
        admin.append(new_admin);
    }

    void edit_admin()
    {
        string target;

        cout << "Please enter the index of the admin to edit or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(admin.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the admin to edit or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << endl;
            cout << "**************" << endl;
            cout << "    Edit" << endl;
            cout << "**************" << endl << endl;
            cout << "[1] Edit Name" << endl;
            cout << "[2] Edit Username" << endl;
            cout << "[3] Edit Password" << endl;
            cout << "[0] Cancel" << endl;
            cout << "Please select the information to edit : ";
            string option;
            fflush(stdin);
            getline(cin, option);
            while (!int_validation(option, false, true, "0", "3"))
            {
                cout << "Invalid input, Please re-enter your choice : ";
                fflush(stdin);
                getline(cin, option);
            }

            admin_struct c = admin.get_data_by_index(string_to_int(target));
            string new_data;
            if (option == "1")
            {
                cout << "Please enter the new Name : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data))
                {
                    cout << "Name should not be empty, Please re-enter the Name : ";
                    fflush(stdin);
                    getline(cin, new_data);
                }
                string name_upper_case;
                for (int i = 0; i < new_data.length(); i++)
                {
                    name_upper_case += toupper(new_data[i]);
                }
                new_data = name_upper_case;
                c.name = new_data;
            }
            else if (option == "2")
            {
                cout << "Please enter the new Username : ";
                fflush(stdin);
                getline(cin, new_data);

                bool not_unique = false;
                admin.init_hashtable(2);
                admin_node *temp_check_unique = admin.hashing_search(2, new_data);
                if (temp_check_unique != NULL)
                {
                    not_unique = true;
                }

                while (!no_null_validation(new_data) || !alpha_number_validation(new_data) || not_unique)
                {
                    if (!no_null_validation(new_data))
                    {
                        cout << "Username should not be empty, Please re-enter the Username : ";
                        fflush(stdin);
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!no_space_only_validation(new_data))
                        {
                            cout << "Invalid input, Please re-enter the Username : ";
                            fflush(stdin);
                            getline(cin, new_data);
                        }
                        else
                        {
                            if (not_unique)
                            {
                                cout << "The Username has been used, Please re-enter the Username : ";
                                fflush(stdin);
                                getline(cin, new_data);
                            }
                        }
                    }
                    not_unique = false;

                    admin.init_hashtable(2);
                    temp_check_unique = admin.hashing_search(2, new_data);
                    if (temp_check_unique != NULL)
                    {
                        not_unique = true;
                    }
                }
                c.username = new_data;
            }
            else if (option == "3")
            {
                cout << "Please enter the new Password : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !no_space_only_validation(new_data))
                {
                    if (!no_null_validation(new_data))
                    {
                        cout << "Password should not be empty, Please re-enter the Password : ";
                        fflush(stdin);
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!no_space_only_validation(new_data))
                        {
                            cout << "Cannot content space in input, Please re-enter the Password : ";
                            fflush(stdin);
                            getline(cin, new_data);
                        }
                    }
                }
                c.password = new_data;
            }
            admin.edit_by_index(string_to_int(target), c);
        }
    }

    void delete_admin()
    {
        string target;
        char confirmation;

        cout << "Please enter the index of the admin to delete or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(admin.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the admin to delete or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << "Are you sure you want to delete? [Y/N] : ";
            cin >> confirmation;
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N')
            {
                cout << "Invalid input, Are you sure you want to delete? [Y/N] : ";
                cin >> confirmation;
            }

            if (toupper(confirmation) == 'Y')
            {
                cout << "\nDeleting the record above..." << endl;
                admin.delete_by_index(string_to_int(target));
            }
        }
    }

    void admins_list(string criteria = "", string keyword = "", string sort = "1")
    {
        if (sort == "1" || sort == "")
        {
            admin.insertionSort(1);
        }
        else if (sort == "2")
        {
            admin.insertionSort(2);
        }
        else if (sort == "3")
        {
            admin.insertionSort(3);
        }
        else if (sort == "4")
        {
            admin.insertionSort(4);
        }
        else if (sort == "5")
        {
            admin.insertionSort(5);
        }
        else if (sort == "6")
        {
            admin.insertionSort(6);
        }

        admin_node *temp = NULL;
        if (criteria == "")
        {
            temp = admin.get_front_pointer();
        }
        else
        {
            if (criteria == "name")
            {
                admin.init_hashtable(1);
                temp = admin.hashing_search(1, keyword);
            }
            else if (criteria == "username")
            {
                admin.init_hashtable(2);
                temp = admin.hashing_search(2, keyword);
            }
        }

        cout << "-----------------------------------------------------------" << endl;
        cout << "|" << setw(5) << left << "Index"
             << "|" << setw(20) << "Name"
             << "|" << setw(30) << "Username"
             << "|" << endl;
        cout << "-----------------------------------------------------------" << endl;
        if (temp == NULL)
        {
            cout << "|                      No Data Found                      |" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << "|" << setw(5) << temp->data.index << "|" << setw(20) << temp->data.name << "|" << setw(30) << temp->data.username << "|" << endl;
                temp = temp->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }
    admin_struct get_admin_data_by_index(int index)
    {
        return admin.get_data_by_index(index);
    }
    admin_node *find_admin_data_by_username(string username)
    {
        admin.init_hashtable(2);
        return admin.hashing_search(2, username);
    }
};

void admins_index()
{
    string criteria = "", keyword = "", option, sort = "1";
    bool repeat = true;
    do
    {
        admins *a = new admins;

        system("CLS");
        a->admins_list(criteria, keyword, sort);
        cout << endl;
        cout << "    Action" << endl;
        cout << "--------------" << endl;
        cout << "[1] Add Admins" << endl;
        cout << "[2] Edit Admins" << endl;
        cout << "[3] Delete Admins" << endl;
        cout << "[4] Search by Name" << endl;
        cout << "[5] Search by Username" << endl;
        cout << "[6] Reset Search" << endl;
        cout << "[7] Sort the List" << endl;
        cout << "[0] Back" << endl;
        cout << "Choose an action : ";
        fflush(stdin);
        getline(cin, option);
        while (!int_validation(option, false, true, "0", "7"))
        {
            cout << "Invalid input, Choose an action : ";
            fflush(stdin);
            getline(cin, option);
        }

        if (option == "1")
        {
            a->create_admin();
        }
        else if (option == "2")
        {
            a->edit_admin();
        }
        else if (option == "3")
        {
            a->delete_admin();
        }
        else if (option == "4")
        {
            criteria = "name";
            cout << "\nEnter Name : ";
            fflush(stdin);
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Name : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "5")
        {
            criteria = "username";
            cout << "\nEnter Username : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Username : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "6")
        {
            criteria = "";
            keyword = "";
        }
        else if (option == "7")
        {
            cout << endl;
            cout << "[1] By Index Ascending" << endl;
            cout << "[2] By Index Descending" << endl;
            cout << "[3] By Name Ascending" << endl;
            cout << "[4] By Name Descending" << endl;
            cout << "[5] By Username Ascending" << endl;
            cout << "[6] By Username Descending" << endl;

            cout << "Sort list by : ";
            fflush(stdin);
            getline(cin, sort);
            while (!int_validation(sort, false, true, "1", "6"))
            {
                cout << "Invalid input, Sort list by : ";
                fflush(stdin);
                getline(cin, sort);
            }
        }
        else if (option == "0")
        {
            repeat = false;
        }
        else
        {
            cout << "Something went wrong";
        }

        delete a;
    } while (repeat);
}

struct user_struct
{
    int index;
    string name;
    string username;
    string password;
    string contact_number;
    string email;
};

struct user_node
{
    user_struct data;
    user_node *next;
};

class user_queue
{
private:
    user_node *front, *rear;
    user_node *hashTable[10];

public:
    user_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(user_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new user_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new user_node;
            front->data = node;
            front->next = NULL;
        }
    }
    user_struct serve()
    {
        user_struct node;
        if (!isEmpty())
        {
            node = front->data;
            user_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        user_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    user_struct get_data_by_index(int index)
    {
        user_node *temp = front;
        user_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    void edit_by_index(int index, user_struct edited_data)
    {
        user_node *temp = front;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            temp->data = edited_data;
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "Edit Error. Data Not found.";
        }
    }
    void delete_by_index(int index)
    {
        user_node *temp = front;
        user_node *prev = temp;

        while (temp != NULL && temp->data.index != index)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
            prev = NULL;
            delete prev;
        }
        else
        {
            cout << "Delete Error. Data Not found.";
        }
    }
    user_node *get_front_pointer()
    {
        return front;
    }
    int compare(const user_struct &a, const user_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else if (sort == 2)
        {
            // Descending order based on index
            return b.index - a.index;
        }
        else if (sort == 3)
        {
            // Ascending order based on name
            return a.name.compare(b.name);
        }
        else if (sort == 4)
        {
            // Descending order based on name
            return b.name.compare(a.name);
        }
        else if (sort == 5)
        {
            // Ascending order based on username
            return a.username.compare(b.username);
        }
        else if (sort == 6)
        {
            // Descending order based on username
            return b.username.compare(a.username);
        }
        else if (sort == 7)
        {
            // Ascending order based on contact_number
            return a.contact_number.compare(b.contact_number);
        }
        else if (sort == 8)
        {
            // Descending order based on contact_number
            return b.contact_number.compare(a.contact_number);
        }
        else if (sort == 9)
        {
            // Ascending order based on email
            return a.email.compare(b.email);
        }
        else if (sort == 10)
        {
            // Descending order based on email
            return b.email.compare(a.email);
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }

    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                user_node *sorted = NULL;
                user_node *current = front;

                while (current != NULL)
                {
                    user_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    user_node *prevSorted = NULL;
                    user_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            user_node *current = hashTable[i];
            while (current != NULL)
            {
                user_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        user_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = current->data.name;
            }
            else if (type == 2)
            {
                key = current->data.username;
            }
            else if (type == 3)
            {
                key = current->data.contact_number;
            }
            else if (type == 4)
            {
                key = current->data.email;
            }
            else if (type == 5)
            {
                key = int_to_string(current->data.index);
            }

            int hashIndex = calculateHashIndex(key);

            user_node *newNode = new user_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                user_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }

    user_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        user_node *resultList = NULL;
        user_node *resultListTail = NULL;

        user_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.name == keyword)
                {
                    user_node *newNode = new user_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 2)
            {
                if (current->data.username == keyword)
                {
                    user_node *newNode = new user_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 3)
            {
                if (current->data.contact_number == keyword)
                {
                    user_node *newNode = new user_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 4)
            {
                if (current->data.email == keyword)
                {
                    user_node *newNode = new user_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 5)
            {
                if (current->data.index == string_to_int(keyword))
                {
                    user_node *newNode = new user_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
    }
};

class users
{
    user_queue user;

public:
    users()
    {
        init();
    }

    ~users()
    {
        store_to_file();
    }

    void init()
    {
        fstream users_file;
        users_file.open("user.txt", ios::in);

        user_struct c;
        int i = 1;

        while (users_file >> c.name >> c.username >> c.password >> c.contact_number >> c.email)
        {
            c.index = i;
            c.name = underscore_to_space(c.name);
            c.username = underscore_to_space(c.username);
            c.password = underscore_to_space(c.password);
            c.contact_number = underscore_to_space(c.contact_number);
            c.email = underscore_to_space(c.email);
            user.append(c);
            i++;
        }
        users_file.close();
    }

    void store_to_file()
    {
        user.insertionSort(1);
        fstream users_file;
        users_file.open("user.txt", ios::out);

        while (!user.isEmpty())
        {
            user_struct c = user.serve();

            c.name = space_to_underscore(c.name);
            c.username = space_to_underscore(c.username);
            c.password = space_to_underscore(c.password);
            c.contact_number = space_to_underscore(c.contact_number);
            c.email = space_to_underscore(c.email);
            users_file << c.name << " " << c.username << " " << c.password << " " << c.contact_number << " " << c.email << endl;
        }
        users_file.close();
    }

    void create_user()
    {
        user_struct new_user;

        cout << "Enter user Name : ";
        fflush(stdin);
        getline(cin, new_user.name);
        while (!no_null_validation(new_user.name))
        {
            fflush(stdin);
            cout << "Name should not be empty, Please re-enter user Name : ";
            getline(cin, new_user.name);
        }

        string name_upper_case;
        for (int i = 0; i < new_user.name.length(); i++)
        {
            name_upper_case += toupper(new_user.name[i]);
        }
        new_user.name = name_upper_case;

        cout << "Enter user Username : ";
        fflush(stdin);
        getline(cin, new_user.username);

        bool not_unique = false;
        user.init_hashtable(2);
        user_node *temp_check_unique = user.hashing_search(2, new_user.username);
        if (temp_check_unique != NULL)
        {
            not_unique = true;
        }

        while (!no_null_validation(new_user.username) || !alpha_number_validation(new_user.username) || not_unique)
        {
            if (!no_null_validation(new_user.username))
            {
                fflush(stdin);
                cout << "Username should not be empty, Please re-enter the Username : ";
                getline(cin, new_user.username);
            }
            else
            {
                if (!alpha_number_validation(new_user.username))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Username : ";
                    getline(cin, new_user.username);
                }
                else
                {
                    if (not_unique)
                    {
                        cout << "The Username has been used, Please re-enter the Username : ";
                        fflush(stdin);
                        getline(cin, new_user.username);
                    }
                }
            }
            not_unique = false;

            user.init_hashtable(2);
            temp_check_unique = user.hashing_search(2, new_user.username);
            if (temp_check_unique != NULL)
            {
                not_unique = true;
            }
        }

        cout << "Enter user password : ";
        fflush(stdin);
        getline(cin, new_user.password);
        while (!no_null_validation(new_user.password) || !no_space_only_validation(new_user.password))
        {
            if (!no_null_validation(new_user.password))
            {
                fflush(stdin);
                cout << "Password should not be empty, Please re-enter the Password : ";
                getline(cin, new_user.password);
            }
            else
            {
                if (!no_space_only_validation(new_user.password))
                {
                    fflush(stdin);
                    cout << "Cannot content space in input, Please re-enter the Password : ";
                    getline(cin, new_user.password);
                }
            }
        }

        cout << "Enter user Contact Number : ";
        fflush(stdin);
        getline(cin, new_user.contact_number);
        while (!no_null_validation(new_user.contact_number) || !int_validation(new_user.contact_number, false, false, "1", "1") || new_user.contact_number.length() > 11 || new_user.contact_number.length() < 10)
        {
            if (!no_null_validation(new_user.contact_number))
            {
                fflush(stdin);
                cout << "Contact Number should not be empty, Please re-enter the Contact Number : ";
                getline(cin, new_user.contact_number);
            }
            else
            {
                if (!int_validation(new_user.contact_number, false, false, "1", "1") || new_user.contact_number.length() > 11 || new_user.contact_number.length() < 10)
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Contact Number, EXP:[0111111111] : ";
                    getline(cin, new_user.contact_number);
                }
            }
        }

        cout << "Enter user Email : ";
        fflush(stdin);
        getline(cin, new_user.email);
        while (!no_null_validation(new_user.email) || !email_validation(new_user.email))
        {
            if (!no_null_validation(new_user.email))
            {
                fflush(stdin);
                cout << "Email should not be empty, Please re-enter the Email : ";
                getline(cin, new_user.email);
            }
            else
            {
                if (!email_validation(new_user.email))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Email : ";
                    getline(cin, new_user.email);
                }
            }
        }

        new_user.index = user.get_total_item() + 1;
        user.append(new_user);
    }

    void edit_user(int user_index = 0)
    {
        string target;

        if (user_index == 0)
        {
            cout << "Please enter the index of the user to edit or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
            while (!int_validation(target, false, true, "0", int_to_string(user.get_total_item())))
            {
                cout << "Invalid input, Please re-enter the index of the user to edit or [0] to cancel : ";
                fflush(stdin);
                getline(cin, target);
            }
        }
        else
        {
            target = int_to_string(user_index);
            cout << endl;
            users_list("index", target);
        }

        if (target != "0")
        {
            cout << endl;
            cout << "**************" << endl;
            cout << "    Edit" << endl;
            cout << "**************" << endl<< endl;
            cout << "[1] Edit Name" << endl;
            cout << "[2] Edit Username" << endl;
            cout << "[3] Edit Password" << endl;
            cout << "[4] Edit Contact Number" << endl;
            cout << "[5] Edit Email" << endl;
            cout << "[0] Cancel" << endl;
            cout << "Please select the information to edit : ";
            string option;
            fflush(stdin);
            getline(cin, option);
            while (!int_validation(option, false, true, "0", "5"))
            {
                cout << "Invalid input, Please re-enter your choice : ";
                fflush(stdin);
                getline(cin, option);
            }

            user_struct c = user.get_data_by_index(string_to_int(target));
            string new_data;
            if (option == "1")
            {
                cout << "Please enter the new Name : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data))
                {
                    cout << "Name should not be empty, Please re-enter the Name : ";
                    fflush(stdin);
                    getline(cin, new_data);
                }
                string name_upper_case;
                for (int i = 0; i < new_data.length(); i++)
                {
                    name_upper_case += toupper(new_data[i]);
                }
                new_data = name_upper_case;
                c.name = new_data;
            }
            else if (option == "2")
            {
                bool not_unique = false;
                cout << "Please enter the new Username : ";
                fflush(stdin);
                getline(cin, new_data);

                user.init_hashtable(2);
                user_node *temp_check_unique = user.hashing_search(2, new_data);
                if (temp_check_unique != NULL)
                {
                    not_unique = true;
                }

                while (!no_null_validation(new_data) || !alpha_number_validation(new_data) || not_unique)
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Username should not be empty, Please re-enter the Username : ";
                        fflush(stdin);
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!alpha_number_validation(new_data))
                        {
                            fflush(stdin);
                            cout << "Invalid input, Please re-enter the Username : ";
                            fflush(stdin);
                            getline(cin, new_data);
                        }
                        else
                        {
                            if (not_unique)
                            {
                                fflush(stdin);
                                cout << "The Username has been used, Please re-enter the Username : ";
                                fflush(stdin);
                                getline(cin, new_data);
                            }
                        }
                    }
                    not_unique = false;

                    user.init_hashtable(2);
                    temp_check_unique = user.hashing_search(2, new_data);
                    if (temp_check_unique != NULL)
                    {
                        not_unique = true;
                    }
                }
                c.username = new_data;
            }
            else if (option == "3")
            {
                cout << "Please enter the new Password : ";
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !no_space_only_validation(new_data))
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Password should not be empty, Please re-enter the Password : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!no_space_only_validation(new_data))
                        {
                            fflush(stdin);
                            cout << "Cannot content space in input, Please re-enter the Password : ";
                            getline(cin, new_data);
                        }
                    }
                }
                c.password = new_data;
            }
            else if (option == "4")
            {
                cout << "Please enter the new Contact Number : ";
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !int_validation(new_data, false, false, "1", "1") || new_data.length() > 11 || new_data.length() < 10)
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Contact Number should not be empty, Please re-enter the Contact Number : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!int_validation(new_data, false, false, "1", "1") || new_data.length() > 11 || new_data.length() < 10)
                        {
                            fflush(stdin);
                            cout << "Invalid input, Please re-enter the Contact Number, EXP:[0111111111] : ";
                            getline(cin, new_data);
                        }
                    }
                }
                c.contact_number = new_data;
            }
            else if (option == "5")
            {
                cout << "Please enter the new Email : ";
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !email_validation(new_data))
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Email should not be empty, Please re-enter the Email : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!email_validation(new_data))
                        {
                            fflush(stdin);
                            cout << "Cannot content space in input, Please re-enter the Email : ";
                            getline(cin, new_data);
                        }
                    }
                }
                c.email = new_data;
            }
            user.edit_by_index(string_to_int(target), c);
        }
    }

    void delete_user()
    {
        string target;
        char confirmation;

        cout << "Please enter the index of the user to delete or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(user.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the user to delete or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << "Are you sure you want to delete? [Y/N] : ";
            cin >> confirmation;
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N')
            {
                cout << "Invalid input, Are you sure you want to delete? [Y/N] : ";
                cin >> confirmation;
            }

            if (toupper(confirmation) == 'Y')
            {
                cout << "\nDeleting the record above..." << endl;
                user.delete_by_index(string_to_int(target));
            }
        }
    }

    void users_list(string criteria = "", string keyword = "", string sort = "1")
    {
        if (sort == "1" || sort == "")
        {
            user.insertionSort(1);
        }
        else if (sort == "2")
        {
            user.insertionSort(2);
        }
        else if (sort == "3")
        {
            user.insertionSort(3);
        }
        else if (sort == "4")
        {
            user.insertionSort(4);
        }
        else if (sort == "5")
        {
            user.insertionSort(5);
        }
        else if (sort == "6")
        {
            user.insertionSort(6);
        }
        else if (sort == "7")
        {
            user.insertionSort(7);
        }
        else if (sort == "8")
        {
            user.insertionSort(8);
        }
        else if (sort == "9")
        {
            user.insertionSort(9);
        }
        else if (sort == "10")
        {
            user.insertionSort(10);
        }

        user_node *temp = NULL;
        if (criteria == "")
        {
            temp = user.get_front_pointer();
        }
        else
        {
            if (criteria == "name")
            {
                user.init_hashtable(1);
                temp = user.hashing_search(1, keyword);
            }
            else if (criteria == "username")
            {
                user.init_hashtable(2);
                temp = user.hashing_search(2, keyword);
            }
            else if (criteria == "contact_number")
            {
                user.init_hashtable(3);
                temp = user.hashing_search(3, keyword);
            }
            else if (criteria == "email")
            {
                user.init_hashtable(4);
                temp = user.hashing_search(4, keyword);
            }
            else if (criteria == "index")
            {
                user.init_hashtable(5);
                temp = user.hashing_search(5, keyword);
            }
        }

        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(5) << left << "Index"
             << "|" << setw(20) << "Name"
             << "|" << setw(20) << "Username"
             << "|" << setw(20) << "Contact Number"
             << "|" << setw(30) << "Email"
             << "|" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        if (temp == NULL)
        {
            cout << "|                                           No Data Found                                           |" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << "|" << setw(5) << temp->data.index << "|" << setw(20) << temp->data.name << "|" << setw(20) << temp->data.username << "|" << setw(20) << temp->data.contact_number << "|" << setw(30) << temp->data.email << "|" << endl;
                temp = temp->next;
            }
        }
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
    }
    user_struct get_user_data_by_index(int index)
    {
        return user.get_data_by_index(index);
    }
    user_node *find_user_data_by_username(string username)
    {
        user.init_hashtable(2);
        return user.hashing_search(2, username);
    }
};

void users_index()
{
    string criteria = "", keyword = "", option, sort = "1";
    bool repeat = true;
    do
    {
        users *a = new users;

        system("CLS");
        a->users_list(criteria, keyword, sort);
        cout << endl;
        cout << "    Action" << endl;
        cout << "--------------" << endl;
        cout << "[1] Add users" << endl;
        cout << "[2] Edit users" << endl;
        cout << "[3] Delete users" << endl;
        cout << "[4] Search by Name" << endl;
        cout << "[5] Search by Username" << endl;
        cout << "[6] Search by Contact Number" << endl;
        cout << "[7] Search by Email" << endl;
        cout << "[8] Reset Search" << endl;
        cout << "[9] Sort the List" << endl;
        cout << "[0] Back" << endl;
        cout << "Choose an action : ";
        fflush(stdin);
        getline(cin, option);
        while (!int_validation(option, false, true, "0", "9"))
        {
            cout << "Invalid input, Choose an action : ";
            fflush(stdin);
            getline(cin, option);
        }

        if (option == "1")
        {
            a->create_user();
        }
        else if (option == "2")
        {
            a->edit_user();
        }
        else if (option == "3")
        {
            a->delete_user();
        }
        else if (option == "4")
        {
            criteria = "name";
            cout << "\nEnter Name : ";
            fflush(stdin);
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Name : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "5")
        {
            criteria = "username";
            cout << "\nEnter Username : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Username : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "6")
        {
            criteria = "contact_number";
            cout << "\nEnter Contact Number : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Contact Number : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "7")
        {
            criteria = "email";
            cout << "\nEnter Email : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Email : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "8")
        {
            criteria = "";
            keyword = "";
        }
        else if (option == "9")
        {
            cout << endl;
            cout << "[1] By Index Ascending" << endl;
            cout << "[2] By Index Descending" << endl;
            cout << "[3] By Name Ascending" << endl;
            cout << "[4] By Name Descending" << endl;
            cout << "[5] By Username Ascending" << endl;
            cout << "[6] By Username Descending" << endl;
            cout << "[7] By Contact Number Ascending" << endl;
            cout << "[8] By Contact Number Descending" << endl;
            cout << "[9] By Email Ascending" << endl;
            cout << "[10] By Email Descending" << endl;

            cout << "Sort list by : ";
            fflush(stdin);
            getline(cin, sort);
            while (!int_validation(sort, false, true, "1", "10"))
            {
                cout << "Invalid input, Sort list by : ";
                fflush(stdin);
                getline(cin, sort);
            }
        }
        else if (option == "0")
        {
            repeat = false;
        }
        else
        {
            cout << "Something went wrong";
        }

        delete a;
    } while (repeat);
}

struct member_struct
{
    int index;
    string name;
    string ic;
    string contact_number;
    string member_code;
};

struct member_node
{
    member_struct data;
    member_node *next;
};

class member_queue
{
private:
    member_node *front, *rear;
    member_node *hashTable[10];

public:
    member_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(member_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new member_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new member_node;
            front->data = node;
            front->next = NULL;
        }
    }
    member_struct serve()
    {
        member_struct node;
        if (!isEmpty())
        {
            node = front->data;
            member_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        member_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    member_struct get_data_by_index(int index)
    {
        member_node *temp = front;
        member_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    void edit_by_index(int index, member_struct edited_data)
    {
        member_node *temp = front;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            temp->data = edited_data;
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "Edit Error. Data Not found.";
        }
    }
    void delete_by_index(int index)
    {
        member_node *temp = front;
        member_node *prev = temp;

        while (temp != NULL && temp->data.index != index)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
            prev = NULL;
            delete prev;
        }
        else
        {
            cout << "Delete Error. Data Not found.";
        }
    }
    member_node *get_front_pointer()
    {
        return front;
    }
    int compare(const member_struct &a, const member_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else if (sort == 2)
        {
            // Descending order based on index
            return b.index - a.index;
        }
        else if (sort == 3)
        {
            // Ascending order based on name
            return a.name.compare(b.name);
        }
        else if (sort == 4)
        {
            // Descending order based on name
            return b.name.compare(a.name);
        }
        else if (sort == 5)
        {
            // Ascending order based on ic
            return a.ic.compare(b.ic);
        }
        else if (sort == 6)
        {
            // Descending order based on ic
            return b.ic.compare(a.ic);
        }
        else if (sort == 7)
        {
            // Ascending order based on contact_number
            return a.contact_number.compare(b.contact_number);
        }
        else if (sort == 8)
        {
            // Descending order based on contact_number
            return b.contact_number.compare(a.contact_number);
        }
        else if (sort == 9)
        {
            // Ascending order based on member_code
            return a.member_code.compare(b.member_code);
        }
        else if (sort == 10)
        {
            // Descending order based on member_code
            return b.member_code.compare(a.member_code);
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }

    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                member_node *sorted = NULL;
                member_node *current = front;

                while (current != NULL)
                {
                    member_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    member_node *prevSorted = NULL;
                    member_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            member_node *current = hashTable[i];
            while (current != NULL)
            {
                member_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        member_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = current->data.name;
            }
            else if (type == 2)
            {
                key = current->data.ic;
            }
            else if (type == 3)
            {
                key = current->data.contact_number;
            }
            else if (type == 4)
            {
                key = current->data.member_code;
            }

            int hashIndex = calculateHashIndex(key);

            member_node *newNode = new member_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                member_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }

    member_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        member_node *resultList = NULL;
        member_node *resultListTail = NULL;

        member_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.name == keyword)
                {
                    member_node *newNode = new member_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 2)
            {
                if (current->data.ic == keyword)
                {
                    member_node *newNode = new member_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 3)
            {
                if (current->data.contact_number == keyword)
                {
                    member_node *newNode = new member_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 4)
            {
                if (current->data.member_code == keyword)
                {
                    member_node *newNode = new member_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
    }
};

class members
{
    member_queue member;

public:
    members()
    {
        init();
    }

    ~members()
    {
        store_to_file();
    }

    void init()
    {
        fstream members_file;
        members_file.open("members.txt", ios::in);

        member_struct c;
        int i = 1;

        while (members_file >> c.name >> c.ic >> c.contact_number >> c.member_code)
        {
            c.index = i;
            c.name = underscore_to_space(c.name);
            c.ic = underscore_to_space(c.ic);
            c.contact_number = underscore_to_space(c.contact_number);
            c.member_code = underscore_to_space(c.member_code);
            member.append(c);
            i++;
        }
        members_file.close();
    }

    void store_to_file()
    {
        member.insertionSort(1);
        fstream members_file;
        members_file.open("members.txt", ios::out);

        while (!member.isEmpty())
        {
            member_struct c = member.serve();

            c.name = space_to_underscore(c.name);
            c.ic = space_to_underscore(c.ic);
            c.contact_number = space_to_underscore(c.contact_number);
            c.member_code = space_to_underscore(c.member_code);
            members_file << c.name << " " << c.ic << " " << c.contact_number << " " << c.member_code << endl;
        }
        members_file.close();
    }

    void create_member()
    {
        member_struct new_member;

        cout << "Enter member Name : ";
        fflush(stdin);
        getline(cin, new_member.name);
        while (!no_null_validation(new_member.name))
        {
            fflush(stdin);
            cout << "Name should not be empty, Please re-enter member Name : ";
            getline(cin, new_member.name);
        }

        string name_upper_case;
        for (int i = 0; i < new_member.name.length(); i++)
        {
            name_upper_case += toupper(new_member.name[i]);
        }
        new_member.name = name_upper_case;

        cout << "Enter member IC : ";
        fflush(stdin);
        getline(cin, new_member.ic);
        while (!no_null_validation(new_member.ic) || !IC_validation(new_member.ic))
        {
            if (!no_null_validation(new_member.ic))
            {
                fflush(stdin);
                cout << "IC should not be empty, Please re-enter the IC : ";
                getline(cin, new_member.ic);
            }
            else
            {
                if (!IC_validation(new_member.ic))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the IC, EXP:[000000-00-0000] : ";
                    getline(cin, new_member.ic);
                }
            }
        }

        cout << "Enter member Contact Number : ";
        fflush(stdin);
        getline(cin, new_member.contact_number);
        while (!no_null_validation(new_member.contact_number) || !int_validation(new_member.contact_number, false, false, "1", "1") || new_member.contact_number.length() > 11 || new_member.contact_number.length() < 10)
        {
            if (!no_null_validation(new_member.contact_number))
            {
                fflush(stdin);
                cout << "Contact Number should not be empty, Please re-enter the Contact Number : ";
                getline(cin, new_member.contact_number);
            }
            else
            {
                if (!int_validation(new_member.contact_number, false, false, "1", "1") || new_member.contact_number.length() > 11 || new_member.contact_number.length() < 10)
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Contact Number, EXP:[0111111111] : ";
                    getline(cin, new_member.contact_number);
                }
            }
        }

        cout << "Enter member Member Code : ";
        fflush(stdin);
        getline(cin, new_member.member_code);

        bool not_unique = false;
        member.init_hashtable(4);
        member_node *temp_check_unique = member.hashing_search(4, new_member.member_code);
        if (temp_check_unique != NULL)
        {
            not_unique = true;
        }

        while (!no_null_validation(new_member.member_code) || not_unique)
        {
            if (!no_null_validation(new_member.member_code))
            {
                fflush(stdin);
                cout << "Member Code should not be empty, Please re-enter the Member Code : ";
                getline(cin, new_member.member_code);
            }
            else
            {
                if (not_unique)
                {
                    cout << "The Member Code has been used, Please re-enter the Member Code : ";
                    fflush(stdin);
                    getline(cin, new_member.member_code);
                }
            }

            not_unique = false;
            member.init_hashtable(4);
            temp_check_unique = member.hashing_search(4, new_member.member_code);
            if (temp_check_unique != NULL)
            {
                not_unique = true;
            }
        }

        new_member.index = member.get_total_item() + 1;
        member.append(new_member);
    }

    void edit_member()
    {
        string target;

        cout << "Please enter the index of the member to edit or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(member.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the member to edit or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << endl;
            cout << "**************" << endl;
            cout << "    Edit" << endl;
            cout << "**************" << endl<< endl;
            cout << "[1] Edit Name" << endl;
            cout << "[2] Edit IC" << endl;
            cout << "[3] Edit Contact Number" << endl;
            cout << "[4] Edit Member Code" << endl;
            cout << "[0] Cancel" << endl;
            cout << "Please select the information to edit : ";
            string option;
            fflush(stdin);
            getline(cin, option);
            while (!int_validation(option, false, true, "0", "4"))
            {
                cout << "Invalid input, Please re-enter your choice : ";
                fflush(stdin);
                getline(cin, option);
            }

            member_struct c = member.get_data_by_index(string_to_int(target));
            string new_data;
            if (option == "1")
            {
                cout << "Please enter the new Name : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data))
                {
                    cout << "Name should not be empty, Please re-enter the Name : ";
                    fflush(stdin);
                    getline(cin, new_data);
                }
                string name_upper_case;
                for (int i = 0; i < new_data.length(); i++)
                {
                    name_upper_case += toupper(new_data[i]);
                }
                new_data = name_upper_case;
                c.name = new_data;
            }
            else if (option == "2")
            {
                cout << "Please enter the new IC : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !IC_validation(new_data))
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "IC should not be empty, Please re-enter the IC : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!IC_validation(new_data))
                        {
                            fflush(stdin);
                            cout << "Invalid input, Please re-enter the IC, EXP:[000000-00-0000] : ";
                            getline(cin, new_data);
                        }
                    }
                }
                c.ic = new_data;
            }
            else if (option == "3")
            {
                cout << "Please enter the new Contact Number : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !int_validation(new_data, false, false, "1", "1") || new_data.length() > 11 || new_data.length() < 10)
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Contact Number should not be empty, Please re-enter the Contact Number : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!int_validation(new_data, false, false, "1", "1") || new_data.length() > 11 || new_data.length() < 10)
                        {
                            fflush(stdin);
                            cout << "Invalid input, Please re-enter the Contact Number, EXP:[0111111111] : ";
                            getline(cin, new_data);
                        }
                    }
                }
                c.contact_number = new_data;
            }
            else if (option == "4")
            {
                cout << "Please enter the new Member Code : ";
                fflush(stdin);
                getline(cin, new_data);

                bool not_unique = false;
                member.init_hashtable(4);
                member_node *temp_check_unique = member.hashing_search(4, new_data);
                if (temp_check_unique != NULL)
                {
                    not_unique = true;
                }

                while (!no_null_validation(new_data) || !no_space_only_validation(new_data) || not_unique)
                {
                    if (!no_null_validation(new_data) || !no_space_only_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Invalid input, Please re-enter the Member Code : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (not_unique)
                        {
                            fflush(stdin);
                            cout << "The Member Code has been used, Please re-enter the Member Code : ";
                            getline(cin, new_data);
                        }
                    }

                    not_unique = false;
                    member.init_hashtable(4);
                    temp_check_unique = member.hashing_search(4, new_data);
                    if (temp_check_unique != NULL)
                    {
                        not_unique = true;
                    }
                }
                c.member_code = new_data;
            }
            member.edit_by_index(string_to_int(target), c);
        }
    }

    void delete_member()
    {
        string target;
        char confirmation;

        cout << "Please enter the index of the member to delete or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(member.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the member to delete or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << "Are you sure you want to delete? [Y/N] : ";
            cin >> confirmation;
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N')
            {
                cout << "Invalid input, Are you sure you want to delete? [Y/N] : ";
                cin >> confirmation;
            }

            if (toupper(confirmation) == 'Y')
            {
                cout << "\nDeleting the record above..." << endl;
                member.delete_by_index(string_to_int(target));
            }
        }
    }

    void members_list(string criteria = "", string keyword = "", string sort = "1")
    {
        if (sort == "1" || sort == "")
        {
            member.insertionSort(1);
        }
        else if (sort == "2")
        {
            member.insertionSort(2);
        }
        else if (sort == "3")
        {
            member.insertionSort(3);
        }
        else if (sort == "4")
        {
            member.insertionSort(4);
        }
        else if (sort == "5")
        {
            member.insertionSort(5);
        }
        else if (sort == "6")
        {
            member.insertionSort(6);
        }
        else if (sort == "7")
        {
            member.insertionSort(7);
        }
        else if (sort == "8")
        {
            member.insertionSort(8);
        }
        else if (sort == "9")
        {
            member.insertionSort(9);
        }
        else if (sort == "10")
        {
            member.insertionSort(10);
        }

        member_node *temp = NULL;
        if (criteria == "")
        {
            temp = member.get_front_pointer();
        }
        else
        {
            if (criteria == "name")
            {
                member.init_hashtable(1);
                temp = member.hashing_search(1, keyword);
            }
            else if (criteria == "ic")
            {
                member.init_hashtable(2);
                temp = member.hashing_search(2, keyword);
            }
            else if (criteria == "contact_number")
            {
                member.init_hashtable(3);
                temp = member.hashing_search(3, keyword);
            }
            else if (criteria == "member_code")
            {
                member.init_hashtable(4);
                temp = member.hashing_search(4, keyword);
            }
        }

        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(5) << left << "Index"
             << "|" << setw(20) << "Name"
             << "|" << setw(20) << "IC"
             << "|" << setw(20) << "Contact Number"
             << "|" << setw(20) << "Member Code"
             << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        if (temp == NULL)
        {
            cout << "|                                      No Data Found                                      |" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << "|" << setw(5) << temp->data.index << "|" << setw(20) << temp->data.name << "|" << setw(20) << temp->data.ic << "|" << setw(20) << temp->data.contact_number << "|" << setw(20) << temp->data.member_code << "|" << endl;
                temp = temp->next;
            }
        }
        cout << "-------------------------------------------------------------------------------------------" << endl;
    }
    member_node *find_member_by_code(string member_code)
    {
        member_node *temp = NULL;
        member.init_hashtable(4);
        temp = member.hashing_search(4, member_code);

        return temp;
    }
};

void members_index()
{
    string criteria = "", keyword = "", option, sort = "1";
    bool repeat = true;
    do
    {
        members *a = new members;

        system("CLS");
        a->members_list(criteria, keyword, sort);
        cout << endl;
        cout << "    Action" << endl;
        cout << "--------------" << endl;
        cout << "[1] Add members" << endl;
        cout << "[2] Edit members" << endl;
        cout << "[3] Delete members" << endl;
        cout << "[4] Search by Name" << endl;
        cout << "[5] Search by IC" << endl;
        cout << "[6] Search by Contact Number" << endl;
        cout << "[7] Search by Member Code" << endl;
        cout << "[8] Reset Search" << endl;
        cout << "[9] Sort the List" << endl;
        cout << "[0] Back" << endl;
        cout << "Choose an action : ";
        fflush(stdin);
        getline(cin, option);
        while (!int_validation(option, false, true, "0", "9"))
        {
            cout << "Invalid input, Choose an action : ";
            fflush(stdin);
            getline(cin, option);
        }

        if (option == "1")
        {
            a->create_member();
        }
        else if (option == "2")
        {
            a->edit_member();
        }
        else if (option == "3")
        {
            a->delete_member();
        }
        else if (option == "4")
        {
            criteria = "name";
            cout << "\nEnter Name : ";
            fflush(stdin);
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Name : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "5")
        {
            criteria = "ic";
            cout << "\nEnter IC : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter IC : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "6")
        {
            criteria = "contact_number";
            cout << "\nEnter Contact Number : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Contact Number : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "7")
        {
            criteria = "member_code";
            cout << "\nEnter Member Code : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Member Code : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "8")
        {
            criteria = "";
            keyword = "";
        }
        else if (option == "9")
        {
            cout << endl;
            cout << "[1] By Index Ascending" << endl;
            cout << "[2] By Index Descending" << endl;
            cout << "[3] By Name Ascending" << endl;
            cout << "[4] By Name Descending" << endl;
            cout << "[5] By IC Ascending" << endl;
            cout << "[6] By IC Descending" << endl;
            cout << "[7] By Contact Number Ascending" << endl;
            cout << "[8] By Contact Number Descending" << endl;
            cout << "[9] By Member Code Ascending" << endl;
            cout << "[10] By Member Code Descending" << endl;

            cout << "Sort list by : ";
            fflush(stdin);
            getline(cin, sort);
            while (!int_validation(sort, false, true, "1", "10"))
            {
                cout << "Invalid input, Sort list by : ";
                fflush(stdin);
                getline(cin, sort);
            }
        }
        else if (option == "0")
        {
            repeat = false;
        }
        else
        {
            cout << "Something went wrong";
        }

        delete a;
    } while (repeat);
}

struct category_struct
{
    int index;
    string name;
};

struct category_node
{
    category_struct data;
    category_node *next;
};

class category_queue
{
private:
    category_node *front, *rear;
    category_node *hashTable[10];

public:
    category_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(category_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new category_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new category_node;
            front->data = node;
            front->next = NULL;
        }
    }
    category_struct serve()
    {
        category_struct node;
        if (!isEmpty())
        {
            node = front->data;
            category_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        category_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    category_struct get_data_by_index(int index)
    {
        category_node *temp = front;
        category_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    void edit_by_index(int index, category_struct edited_data)
    {
        category_node *temp = front;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            temp->data = edited_data;
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "Edit Error. Data Not found.";
        }
    }
    void delete_by_index(int index)
    {
        category_node *temp = front;
        category_node *prev = temp;

        while (temp != NULL && temp->data.index != index)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
            prev = NULL;
            delete prev;
        }
        else
        {
            cout << "Delete Error. Data Not found.";
        }
    }
    category_node *get_front_pointer()
    {
        return front;
    }
    int compare(const category_struct &a, const category_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else if (sort == 2)
        {
            // Descending order based on index
            return b.index - a.index;
        }
        else if (sort == 3)
        {
            // Ascending order based on name
            return a.name.compare(b.name);
        }
        else if (sort == 4)
        {
            // Descending order based on name
            return b.name.compare(a.name);
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }

    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                category_node *sorted = NULL;
                category_node *current = front;

                while (current != NULL)
                {
                    category_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    category_node *prevSorted = NULL;
                    category_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            category_node *current = hashTable[i];
            while (current != NULL)
            {
                category_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        category_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = current->data.name;
            }

            int hashIndex = calculateHashIndex(key);

            category_node *newNode = new category_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                category_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }

    category_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        category_node *resultList = NULL;
        category_node *resultListTail = NULL;

        category_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.name == keyword)
                {
                    category_node *newNode = new category_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
    }
};

class categories
{
    category_queue category;

public:
    categories()
    {
        init();
    }

    ~categories()
    {
        store_to_file();
    }

    void init()
    {
        fstream categories_file;
        categories_file.open("categories.txt", ios::in);

        category_struct c;
        int i = 1;
                

        while (categories_file >> c.name)
        {
            c.index = i;
            c.name = underscore_to_space(c.name);
            category.append(c);
            i++;
        }
        categories_file.close();
    }

    void store_to_file()
    {
        category.insertionSort(1);
        fstream categories_file;
        categories_file.open("categories.txt", ios::out);

        while (!category.isEmpty())
        {
            category_struct c = category.serve();

            c.name = space_to_underscore(c.name);
            categories_file << c.name << endl;
        }
        categories_file.close();
    }

    void create_category()
    {
        category_struct new_category;

        cout << "Enter category Name : ";
        fflush(stdin);
        getline(cin, new_category.name);

        bool not_unique = false;
        category.init_hashtable(1);
        category_node *temp_check_unique = category.hashing_search(1, new_category.name);
        if (temp_check_unique != NULL)
        {
            not_unique = true;
        }

        while (!no_null_validation(new_category.name) || not_unique)
        {
            if (!no_null_validation(new_category.name))
            {
                fflush(stdin);
                cout << "Name should not be empty, Please re-enter category Name : ";
                getline(cin, new_category.name);
            }
            else
            {
                if (not_unique)
                {
                    fflush(stdin);
                    cout << "The Name has been used, Please re-enter the Name : ";
                    getline(cin, new_category.name);
                }
            }

            not_unique = false;
            category.init_hashtable(1);
            temp_check_unique = category.hashing_search(1, new_category.name);
            if (temp_check_unique != NULL)
            {
                not_unique = true;
            }
        }

        new_category.index = category.get_total_item() + 1;
        category.append(new_category);
    }

    void edit_category()
    {
        string target;

        cout << "Please enter the index of the category to edit or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(category.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the category to edit or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << endl;
            cout << "**************" << endl;
            cout << "    Edit" << endl;
            cout << "**************" << endl;
            cout << "[1] Edit Name" << endl;
            cout << "[0] Cancel" << endl;
            cout << "Please select the information to edit : ";
            string option;
            fflush(stdin);
            getline(cin, option);
            while (!int_validation(option, false, true, "0", "1"))
            {
                cout << "Invalid input, Please re-enter your choice : ";
                fflush(stdin);
                getline(cin, option);
            }

            category_struct c = category.get_data_by_index(string_to_int(target));
            string new_data;
            if (option == "1")
            {
                cout << "Please enter the new Name : ";
                fflush(stdin);
                getline(cin, new_data);

                bool not_unique = false;
                category.init_hashtable(1);
                category_node *temp_check_unique = category.hashing_search(1, new_data);
                if (temp_check_unique != NULL)
                {
                    not_unique = true;
                }

                while (!no_null_validation(new_data) || not_unique)
                {
                    if (!no_null_validation(new_data))
                    {
                        cout << "Name should not be empty, Please re-enter the Name : ";
                        fflush(stdin);
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (not_unique)
                        {
                            cout << "The Name has been used, Please re-enter the Name : ";
                            fflush(stdin);
                            getline(cin, new_data);
                        }
                    }
                }

                not_unique = false;
                category.init_hashtable(1);
                temp_check_unique = category.hashing_search(1, new_data);
                if (temp_check_unique != NULL)
                {
                    not_unique = true;
                }
                c.name = new_data;
            }
            category.edit_by_index(string_to_int(target), c);
        }
    }

    void delete_category()
    {
        string target;
        char confirmation;

        cout << "Please enter the index of the category to delete or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(category.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the category to delete or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << "Are you sure you want to delete? [Y/N] : ";
            cin >> confirmation;
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N')
            {
                cout << "Invalid input, Are you sure you want to delete? [Y/N] : ";
                cin >> confirmation;
            }

            if (toupper(confirmation) == 'Y')
            {
                cout << "\nDeleting the record above..." << endl;
                category.delete_by_index(string_to_int(target));
            }
        }
    }

    void categories_list(string criteria = "", string keyword = "", string sort = "1")
    {
        if (sort == "1" || sort == "")
        {
            category.insertionSort(1);
        }
        else if (sort == "2")
        {
            category.insertionSort(2);
        }
        else if (sort == "3")
        {
            category.insertionSort(3);
        }
        else if (sort == "4")
        {
            category.insertionSort(4);
        }

        category_node *temp = NULL;
        if (criteria == "")
        {
            temp = category.get_front_pointer();
        }
        else
        {
            if (criteria == "name")
            {
                category.init_hashtable(1);
                temp = category.hashing_search(1, keyword);
            }
        }

        cout << "--------------------------------------" << endl;
        cout << "|" << setw(5) << left << "Index"
             << "|" << setw(30) << "Name"
             << "|" << endl;
        cout << "--------------------------------------" << endl;
        if (temp == NULL)
        {
            cout << "|            No Data Found           |" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << "|" << setw(5) << temp->data.index << "|" << setw(30) << temp->data.name << "|" << endl;
                temp = temp->next;
            }
        }
        cout << "--------------------------------------" << endl;
    }
    category_struct get_category_data_by_index(string index)
    {
        return category.get_data_by_index(string_to_int(index));
    }
    int get_category_count()
    {
        return category.get_total_item();
    }
};

void categories_index()
{
    string criteria = "", keyword = "", option, sort = "1";
    bool repeat = true;
    do
    {
        categories *a = new categories;

        system("CLS");
        a->categories_list(criteria, keyword, sort);
        cout << endl;
        cout << "    Action" << endl;
        cout << "--------------" << endl;
        cout << "[1] Add categories" << endl;
        cout << "[2] Edit categories" << endl;
        cout << "[3] Delete categories" << endl;
        cout << "[4] Search by Name" << endl;
        cout << "[5] Reset Search" << endl;
        cout << "[6] Sort the List" << endl;
        cout << "[0] Back" << endl;
        cout << "Choose an action : ";
        fflush(stdin);
        getline(cin, option);
        while (!int_validation(option, false, true, "0", "6"))
        {
            cout << "Invalid input, Choose an action : ";
            fflush(stdin);
            getline(cin, option);
        }

        if (option == "1")
        {
            a->create_category();
        }
        else if (option == "2")
        {
            a->edit_category();
        }
        else if (option == "3")
        {
            a->delete_category();
        }
        else if (option == "4")
        {
            criteria = "name";
            cout << "\nEnter Name : ";
            fflush(stdin);
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Name : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "5")
        {
            criteria = "";
            keyword = "";
        }
        else if (option == "6")
        {
            cout << endl;
            cout << "[1] By Index Ascending" << endl;
            cout << "[2] By Index Descending" << endl;
            cout << "[3] By Name Ascending" << endl;
            cout << "[4] By Name Descending" << endl;

            cout << "Sort list by : ";
            fflush(stdin);
            getline(cin, sort);
            while (!int_validation(sort, false, true, "1", "4"))
            {
                cout << "Invalid input, Sort list by : ";
                fflush(stdin);
                getline(cin, sort);
            }
        }
        else if (option == "0")
        {
            repeat = false;
        }
        else
        {
            cout << "Something went wrong";
        }

        delete a;
    } while (repeat);
}

struct coffee_struct
{
    int index;
    string name;
    string sugar;
    string size;
    float price;
    string category;
};

struct coffee_node
{
    coffee_struct data;
    coffee_node *next;
};

class coffee_queue
{
private:
    coffee_node *front, *rear;
    coffee_node *hashTable[10];
    
    
public:
    coffee_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(coffee_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new coffee_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new coffee_node;
            front->data = node;
            front->next = NULL;
        }
    }
    coffee_struct serve()
    {
        coffee_struct node;
        if (!isEmpty())
        {
            node = front->data;
            coffee_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        coffee_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    coffee_struct get_data_by_index(int index)
    {
        coffee_node *temp = front;
        coffee_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    void edit_by_index(int index, coffee_struct edited_data)
    {
        coffee_node *temp = front;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            temp->data = edited_data;
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "Edit Error. Data Not found.";
        }
    }
    void delete_by_index(int index)
    {
        coffee_node *temp = front;
        coffee_node *prev = temp;

        while (temp != NULL && temp->data.index != index)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
            prev = NULL;
            delete prev;
        }
        else
        {
            cout << "Delete Error. Data Not found.";
        }
    }
    coffee_node *get_front_pointer()
    {
        return front;
    }
    int compare(const coffee_struct &a, const coffee_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else if (sort == 2)
        {
            // Descending order based on index
            return b.index - a.index;
        }
        else if (sort == 3)
        {
            // Ascending order based on name
            return a.name.compare(b.name);
        }
        else if (sort == 4)
        {
            // Descending order based on name
            return b.name.compare(a.name);
        }
        else if (sort == 5)
        {
            // Ascending order based on 
            return a.sugar.compare(b.sugar);
        }
        else if (sort == 6)
        {
            // Descending order based on sugar
            return b.sugar.compare(a.sugar);
        }
        else if (sort == 7)
        {
            // Ascending order based on size
            return a.size.compare(b.size);
        }
        else if (sort == 8)
        {
            // Descending order based on size
            return b.size.compare(a.size);
        }
        else if (sort == 9)
        {
            // Ascending order based on price
            if (a.price < b.price)
                return -1;
            if (a.price > b.price)
                return 1;
        }
        else if (sort == 10)
        {
            // Descending order based on price
            if (a.price > b.price)
                return -1;
            if (a.price < b.price)
                return 1;
        }
        else if (sort == 11)
        {
            // Ascending order based on category
            return a.category.compare(b.category);
        }
        else if (sort == 12)
        {
            // Descending order based on category
            return b.category.compare(a.category);
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }

    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                coffee_node *sorted = NULL;
                coffee_node *current = front;

                while (current != NULL)
                {
                    coffee_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    coffee_node *prevSorted = NULL;
                    coffee_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            coffee_node *current = hashTable[i];
            while (current != NULL)
            {
                coffee_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        coffee_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = current->data.name;
            }
            else if (type == 2)
            {
                key = current->data.sugar;
            }
            else if (type == 3)
            {
                key = current->data.size;
            }
            else if (type == 4)
            {
                key = float_to_string(current->data.price);
            }
            else if (type == 5)
            {
                key = current->data.category;
            }

            int hashIndex = calculateHashIndex(key);

            coffee_node *newNode = new coffee_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                coffee_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }
	
    coffee_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        coffee_node *resultList = NULL;
        coffee_node *resultListTail = NULL;

        coffee_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.name == keyword)
                {
                    coffee_node *newNode = new coffee_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 2)
            {
                if (current->data.sugar == keyword)
                {
                    coffee_node *newNode = new coffee_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 3)
            {
                if (current->data.size == keyword)
                {
                    coffee_node *newNode = new coffee_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            
   		else if (type == 4)
		{
		   
		    if (current->data.price == string_to_float(keyword))
		    {
		        coffee_node *newNode = new coffee_node;
		        newNode->data = current->data;
		        newNode->next = NULL;
		
		        if (resultList == NULL)
		        {
		            resultList = newNode;
		            resultListTail = newNode;
		        }
		        else
		        {
		            resultListTail->next = newNode;
		            resultListTail = resultListTail->next;
		        }
		    }
		}
			else if (type == 5)
            {
                if (current->data.category == keyword)
                {
                    coffee_node *newNode = new coffee_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
}
	};
class coffees
{
    coffee_queue coffee;

public:
    coffees()
    {
        init();
    }

    ~coffees()
    {
        store_to_file();
    }

    void init()
    {
        fstream coffees_file;
        coffees_file.open("coffee.txt", ios::in);

        coffee_struct c;
        int i = 1;

        while (coffees_file >> c.name >> c.sugar >> c.size >> c.price >> c.category)
        {
            c.index = i;
            c.name = underscore_to_space(c.name);
            c.sugar = underscore_to_space(c.sugar);
            c.size = underscore_to_space(c.size);
            c.category = underscore_to_space(c.category);
            coffee.append(c);
            i++;
        }
        coffees_file.close();
    }

    void store_to_file()
    {
        coffee.insertionSort(1);
        fstream coffees_file;
        coffees_file.open("coffee.txt", ios::out);

        while (!coffee.isEmpty())
        {
            coffee_struct c = coffee.serve();

            c.name = space_to_underscore(c.name);
            c.sugar = space_to_underscore(c.sugar);
            c.size = space_to_underscore(c.size);
            c.category = space_to_underscore(c.category);
            coffees_file << c.name << " " << c.sugar << " " << c.size << " " << c.price << " " << c.category << endl;
        }
        coffees_file.close();
    }

    void create_coffee()
    {
        coffee_struct new_coffee;

        cout << "Enter coffee Name : ";
        fflush(stdin);
        getline(cin, new_coffee.name);
        while (!no_null_validation(new_coffee.name))
        {
            fflush(stdin);
            cout << "Name should not be empty, Please re-enter coffee Name : ";
            getline(cin, new_coffee.name);
        }

        cout << "Enter coffee sugar : ";
        fflush(stdin);
        getline(cin, new_coffee.sugar);
        while (!no_null_validation(new_coffee.sugar))
        {
            fflush(stdin);
            cout << "sugar should not be empty, Please re-enter the sugar level: ";
            getline(cin, new_coffee.sugar);
        }

        cout << "Enter coffee cup size : ";
        fflush(stdin);
        getline(cin, new_coffee.size);
        while (!no_null_validation(new_coffee.size))
        {                                          
           
            if (!no_null_validation(new_coffee.size))
            {     fflush(stdin);
                cout << "Size should not be empty, Please re-enter the Cup Size : ";
                getline(cin, new_coffee.size);
                                           
            }
            else
            {
                if (!int_validation(new_coffee.size, false, false, "0", "0"))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Cup Size : ";
                    getline(cin, new_coffee.size);
                }
            }
	}
	
	string coffees_price;
        cout << "Enter coffee Price : RM ";
        fflush(stdin);
        getline(cin, coffees_price);
        while (!no_null_validation(coffees_price) || !float_validation(coffees_price, false))
        {
            if (!no_null_validation(coffees_price))
            {
                fflush(stdin);
                cout << "Price should not be empty, Please re-enter the Price : RM ";
                getline(cin, coffees_price);
            }
            else
            {
                if (!float_validation(coffees_price, false))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Price : RM ";
                    getline(cin, coffees_price);
                }
            }
        }
        new_coffee.price = string_to_float(coffees_price);

        categories *c = new categories;
        c->categories_list();

        cout << "Enter coffee Category Index : ";
        fflush(stdin);
        getline(cin, new_coffee.category);
        while (!no_null_validation(new_coffee.category) || !int_validation(new_coffee.category, false, true, "1", int_to_string(c->get_category_count())))
        {
            if (!no_null_validation(new_coffee.category))
            {
                fflush(stdin);
                cout << "Category should not be empty, Please re-enter the Category Index : ";
                getline(cin, new_coffee.category);
            }
            else
            {
                if (!int_validation(new_coffee.category, false, true, "1", int_to_string(c->get_category_count())))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Category Index : ";
                    getline(cin, new_coffee.category);
                }
            }
        }
        new_coffee.category = c->get_category_data_by_index(new_coffee.category).name;
        new_coffee.index = coffee.get_total_item() + 1;
        coffee.append(new_coffee);
        delete c;
    }

    void edit_coffee()
    {
        string target;

        cout << "Please enter the index of the coffee to edit or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(coffee.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the coffee to edit or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << endl;
            cout << "**************" << endl;
            cout << "    Edit" << endl;
            cout << "**************" << endl<< endl;
            cout << "[1] Edit Name" << endl;
            cout << "[2] Edit Sugar" << endl;
            cout << "[3] Edit Cup Size" << endl;
            cout << "[4] Edit Price" << endl;
            cout << "[5] Edit Category" << endl;
            cout << "[0] Cancel" << endl;
            cout << "Please select the information to edit : ";
            string option;
            fflush(stdin);
            getline(cin, option);
            while (!int_validation(option, false, true, "0", "5"))
            {
                cout << "Invalid input, Please re-enter your choice : ";
                fflush(stdin);
                getline(cin, option);
            }

            coffee_struct c = coffee.get_data_by_index(string_to_int(target));
            string new_data;
            if (option == "1")
            {
                cout << "Please enter the new Name : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data))
                {
                    cout << "Name should not be empty, Please re-enter the Name : ";
                    fflush(stdin);
                    getline(cin, new_data);
                }
                c.name = new_data;
            }
            else if (option == "2")
            {
                cout << "Please enter the new sugar : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data))
                {
                    fflush(stdin);
                    cout << "sugar should not be empty, Please re-enter the sugar : ";
                    getline(cin, new_data);
                }
                c.sugar = new_data;
            }
            else if (option == "3")
            {
                cout << "Please enter the new Cup Size : ";
                fflush(stdin);
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !int_validation(new_data, false, false, "0", "0"))
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Cup Size should not be empty, Please re-enter the Cup Size : ";
                        getline(cin, new_data);
                    }
                   
                }
                c.size = new_data;
            }
            else if (option == "4")
            {
                cout << "Please enter the new Price : RM ";
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !float_validation(new_data, false))
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Price should not be empty, Please re-enter the Price : RM ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!float_validation(new_data, false))
                        {
                            fflush(stdin);
                            cout << "Invalid input, Please re-enter the Price : RM ";
                            getline(cin, new_data);
                        }
                    }
                }
                c.price = string_to_float(new_data);
            }
            else if (option == "5")
            {
                categories *ca = new categories;
                ca->categories_list();

                cout << "Please enter the new Category Index : ";
                getline(cin, new_data);
                while (!no_null_validation(new_data) || !int_validation(new_data, false, true, "1", int_to_string(ca->get_category_count())))
                {
                    if (!no_null_validation(new_data))
                    {
                        fflush(stdin);
                        cout << "Category should not be empty, Please re-enter the Category Index : ";
                        getline(cin, new_data);
                    }
                    else
                    {
                        if (!int_validation(new_data, false, true, "1", int_to_string(ca->get_category_count())))
                        {
                            fflush(stdin);
                            cout << "Invalid input, Please re-enter the Category Index : ";
                            getline(cin, new_data);
                        }
                    }
                }
            	
                c.category = ca->get_category_data_by_index(new_data).name;

                delete ca;
            }
            coffee.edit_by_index(string_to_int(target), c);
        }
    }

    void delete_coffee()
    {
        string target;
        char confirmation;

        cout << "Please enter the index of the coffee to delete or [0] to cancel : ";
        fflush(stdin);
        getline(cin, target);
        while (!int_validation(target, false, true, "0", int_to_string(coffee.get_total_item())))
        {
            cout << "Invalid input, Please re-enter the index of the coffee to delete or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
        }

        if (target != "0")
        {
            cout << "Are you sure you want to delete? [Y/N] : ";
            cin >> confirmation;
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N')
            {
                cout << "Invalid input, Are you sure you want to delete? [Y/N] : ";
                cin >> confirmation;
            }

            if (toupper(confirmation) == 'Y')
            {
                cout << "\nDeleting the record above..." << endl;
                coffee.delete_by_index(string_to_int(target));
            }
        }
    }

    void coffees_list(string criteria = "", string keyword = "", string sort = "1")
    {
        if (sort == "1" || sort == "")
        {
            coffee.insertionSort(1);
        }
        else if (sort == "2")
        {
            coffee.insertionSort(2);
        }
        else if (sort == "3")
        {
            coffee.insertionSort(3);
        }
        else if (sort == "4")
        {
            coffee.insertionSort(4);
        }
        else if (sort == "5")
        {
            coffee.insertionSort(5);
        }
        else if (sort == "6")
        {
            coffee.insertionSort(6);
        }
        else if (sort == "7")
        {
            coffee.insertionSort(7);
        }
        else if (sort == "8")
        {
            coffee.insertionSort(8);
        }
        else if (sort == "9")
        {
            coffee.insertionSort(9);
        }
        else if (sort == "10")
        {
            coffee.insertionSort(10);
        }
        else if (sort == "11")
        {
            coffee.insertionSort(11);
        }
        else if (sort == "12")
        {
            coffee.insertionSort(12);
        }
        
          coffee_node *temp = NULL;
          
	 if (criteria == "")
        {
            temp = coffee.get_front_pointer();
        }
        else
        {
            if (criteria == "name")
            {
                coffee.init_hashtable(1);
                temp = coffee.hashing_search(1, keyword);
            }
            else if (criteria == "sugar")
            {
                coffee.init_hashtable(2);
                temp = coffee.hashing_search(2, keyword);
            }
            else if (criteria == "size")
            {
                coffee.init_hashtable(3);
                temp = coffee.hashing_search(3, keyword);
            }
            else if (criteria == "price")
			{
			    coffee.init_hashtable(4);
			    temp = coffee.hashing_search(4, keyword);
			}
            else if (criteria == "category")
            {
                coffee.init_hashtable(5);
                temp = coffee.hashing_search(5, keyword);
            }
        }

        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(5) << left << "Index"
             << "|" << setw(40) << "Name"
             << "|" << setw(20) << "Sugar"
             << "|" << setw(10) << right << "Cup Size"
             << "|" << setw(10) << "Price"
             << "|" << setw(20) << left << "Category"
             << "|" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        
		if (temp == NULL)
        {
            cout << "|                                                 No Data Found                                                |" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << fixed << setprecision(2);

                stringstream ss;
                ss << fixed << setprecision(2) << "RM " << temp->data.price;

                cout << "|" << setw(5) << left << temp->data.index << "|" << setw(40) << temp->data.name << "|" << setw(20) << temp->data.sugar << "|" << setw(10) << right << temp->data.size << "|" << setw(10) << ss.str() << "|" << setw(20) << left << temp->data.category << "|" << endl;
                temp = temp->next;
            }
        }
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    }
    coffee_struct get_coffee_data_by_index(string index)
    {
        return coffee.get_data_by_index(string_to_int(index));
    }
    int get_coffee_count()
    {
        return coffee.get_total_item();
    }
};


void coffees_index()
{
    string criteria = "", keyword = "", option, sort = "1";
    bool repeat = true;
    do
    {
        coffees *a = new coffees;

        system("CLS");
        a->coffees_list(criteria, keyword, sort);
        cout << endl;
        cout << "    Action" << endl;
        cout << "--------------" << endl;
        cout << "[1] Add coffees" << endl;
        cout << "[2] Edit coffees" << endl;
        cout << "[3] Delete coffees" << endl;
        cout << "[4] Search by Name" << endl;
        cout << "[5] Search by Sugar Level" << endl;
        cout << "[6] Search by Cup Size" << endl;
        cout << "[7] Search by Price" << endl;
        cout << "[8] Search by Category" << endl;
        cout << "[9] Reset Search" << endl;
        cout << "[10] Sort the List" << endl;
        cout << "[0] Back" << endl;
        cout << "Choose an action : ";
        fflush(stdin);
        getline(cin, option);
        while (!int_validation(option, false, true, "0", "10"))
        {
            cout << "Invalid input, Choose an action : ";
            fflush(stdin);
            getline(cin, option);
        }

        if (option == "1")
        {
            a->create_coffee();
        }
        else if (option == "2")
        {
            a->edit_coffee();
        }
        else if (option == "3")
        {
            a->delete_coffee();
        }
        else if (option == "4")
        {
            criteria = "name";
            cout << "\nEnter Name : ";
            fflush(stdin);
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Name : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "5")
        {
            criteria = "sugar";
            cout << "\nEnter sugar level: ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter sugar level: ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "6")
        {
            criteria = "size";
            cout << "\nEnter Cup Size : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Cup Size : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "7")
        {
            criteria = "price";
            cout << "\nEnter Price : RM ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Price : RM ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "8")
        {
            criteria = "category";
            cout << "\nEnter Category : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Category : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "9")
        {
            criteria = "";
            keyword = "";
        }
        else if (option == "10")
        {
            cout << endl;
            cout << "[1] By Index Ascending" << endl;
            cout << "[2] By Index Descending" << endl;
            cout << "[3] By Name Ascending" << endl;
            cout << "[4] By Name Descending" << endl;
            cout << "[5] By Sugar Level Ascending" << endl;
            cout << "[6] By Sugar Level Descending" << endl;
            cout << "[7] By Cup Size Ascending" << endl;
            cout << "[8] By Cup Size Descending" << endl;
            cout << "[9] By Price Ascending" << endl;
            cout << "[10] By Price Descending" << endl;
            cout << "[11] By Category Ascending" << endl;
            cout << "[12] By Category Descending" << endl;

            cout << "Sort list by : ";
            fflush(stdin);
            getline(cin, sort);
            while (!int_validation(sort, false, true, "1", "12"))
            {
                cout << "Invalid input, Sort list by : ";
                fflush(stdin);
                getline(cin, sort);
            }
        }
        else if (option == "0")
        {
            repeat = false;
        }
        else
        {
            cout << "Something went wrong";
        }

        delete a;
    } while (repeat);
}

struct order_detail_struct
{
    int index;
    string coffees_name;
    string coffees_sugar;
    string coffees_size;
    int qty;
    float price;
    float total_price;
    int orders_index;
};

struct order_detail_node
{
    order_detail_struct data;
    order_detail_node *next;
};

class order_detail_queue
{
private:
    order_detail_node *front, *rear;
    order_detail_node *hashTable[10];

public:
    order_detail_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(order_detail_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new order_detail_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new order_detail_node;
            front->data = node;
            front->next = NULL;
        }
    }
    order_detail_struct serve()
    {
        order_detail_struct node;
        if (!isEmpty())
        {
            node = front->data;
            order_detail_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        order_detail_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    order_detail_struct get_data_by_index(int index)
    {
        order_detail_node *temp = front;
        order_detail_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    order_detail_node *get_front_pointer()
    {
        return front;
    }
    int compare(const order_detail_struct &a, const order_detail_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }

    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                order_detail_node *sorted = NULL;
                order_detail_node *current = front;

                while (current != NULL)
                {
                    order_detail_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    order_detail_node *prevSorted = NULL;
                    order_detail_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            order_detail_node *current = hashTable[i];
            while (current != NULL)
            {
                order_detail_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        order_detail_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = int_to_string(current->data.orders_index);
            }

            int hashIndex = calculateHashIndex(key);

            order_detail_node *newNode = new order_detail_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                order_detail_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }

    order_detail_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        order_detail_node *resultList = NULL;
        order_detail_node *resultListTail = NULL;

        order_detail_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.orders_index == string_to_int(keyword))
                {
                    order_detail_node *newNode = new order_detail_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
    }
};

class order_details
{
    order_detail_queue order_detail;

public:
    order_details()
    {
        init_order_details();
    }

    ~order_details()
    {
        store_to_file_order_details();
    }

    void init_order_details()
    {
        fstream order_details_file;
        order_details_file.open("order_details.txt", ios::in);

        order_detail_struct c;

        while (order_details_file >> c.index >> c.coffees_name >> c.coffees_sugar >> c.coffees_size >> c.qty >> c.price >> c.total_price >> c.orders_index)
        {
            c.coffees_name = underscore_to_space(c.coffees_name);
            c.coffees_sugar = underscore_to_space(c.coffees_sugar);
            c.coffees_size = underscore_to_space(c.coffees_size);
            order_detail.append(c);
        }
        order_details_file.close();
    }

    void store_to_file_order_details()
    {
        order_detail.insertionSort(1);
        fstream order_details_file;
        order_details_file.open("order_details.txt", ios::out);

        while (!order_detail.isEmpty())
        {
        	
            order_detail_struct c = order_detail.serve();
            c.coffees_name = space_to_underscore(c.coffees_name);
            c.coffees_sugar = space_to_underscore(c.coffees_sugar);
            c.coffees_size = space_to_underscore(c.coffees_size);

            order_details_file << c.index << " " << c.coffees_name << " " << c.coffees_sugar << " " << c.coffees_size << " " << c.qty << " " << c.price << " " << c.total_price << " " << c.orders_index << endl;
        }
        order_details_file.close();
    }

    void create_order_detail(order_detail_node *temp)
    {
        while (temp != NULL)
        {
            order_detail_struct new_order_detail;
            new_order_detail.index = temp->data.index;
            new_order_detail.coffees_name = temp->data.coffees_name;
            new_order_detail.coffees_sugar = temp->data.coffees_sugar;
            new_order_detail.coffees_size = temp->data.coffees_size;
            new_order_detail.price = temp->data.price;
            new_order_detail.qty = temp->data.qty;
            new_order_detail.total_price = temp->data.total_price;
            new_order_detail.orders_index = temp->data.orders_index;
            order_detail.append(new_order_detail);
            temp = temp->next;
        }
    }

    void display_order_detail(string order_index)
    {
        order_detail.init_hashtable(1);
        order_detail_node *temp = order_detail.hashing_search(1, order_index);

        while (temp != NULL)
        {
            cout << fixed << setprecision(2);

            stringstream ss;
            ss << fixed << setprecision(2) << "RM " << temp->data.total_price;

            cout << left << setw(3) << temp->data.qty << setw(40) << temp->data.coffees_name << setw(20) << temp->data.coffees_sugar << setw(4) << temp->data.coffees_size << setw(10) << right << ss.str() << endl;
            temp = temp->next;
        }
    }
    int get_order_detail_total_item()
    {
        return order_detail.get_total_item();
    }
};

struct order_struct
{
    int index;
    string trans_code;
    string order_at;
    float total_price;
    bool has_member;
    string member_name;
    string member_code;
};

struct order_node
{
    order_struct data;
    order_node *next;
};

class order_queue
{
private:
    order_node *front, *rear;
    order_node *hashTable[10];

public:
    order_queue()
    {
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = NULL;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(order_struct node)
    {
        if (rear != NULL)
        {
            rear->next = new order_node;
            rear = rear->next;
            rear->data = node;
            rear->next = NULL;
        }
        else
        {
            front = rear = new order_node;
            front->data = node;
            front->next = NULL;
        }
    }
    order_struct serve()
    {
        order_struct node;
        if (!isEmpty())
        {
            node = front->data;
            order_node *temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
            return node;
        }
    }
    int get_total_item()
    {
        order_node *temp = front;
        int total = 0;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        temp = NULL;
        delete temp;

        return total;
    }
    order_struct get_data_by_index(int index)
    {
        order_node *temp = front;
        order_struct data;

        while (temp != NULL && temp->data.index != index)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            data = temp->data;
        }

        return data;
    }
    order_node *get_front_pointer()
    {
        return front;
    }
    int compare(const order_struct &a, const order_struct &b, int sort)
    {
        if (sort == 1)
        {
            // Ascending order based on index
            return a.index - b.index;
        }
        else if (sort == 2)
        {
            // Descending order based on index
            return b.index - a.index;
        }
        else if (sort == 3)
        {
            // Ascending order based on trans_code
            return a.trans_code.compare(b.trans_code);
        }
        else if (sort == 4)
        {
            // Descending order based on trans_code
            return b.trans_code.compare(a.trans_code);
        }
        else if (sort == 5)
        {
            // Ascending order based on order_at
            return a.order_at.compare(b.order_at);
        }
        else if (sort == 6)
        {
            // Descending order based on order_at
            return b.order_at.compare(a.order_at);
        }
        else if (sort == 7)
        {
            // Ascending order based on total_price
            if (a.total_price < b.total_price)
                return -1;
            if (a.total_price > b.total_price)
                return 1;
        }
        else if (sort == 8)
        {
            // Descending order based on total_price
            if (a.total_price > b.total_price)
                return -1;
            if (a.total_price < b.total_price)
                return 1;
        }
        else if (sort == 9)
        {
            // Ascending order based on member_code
            return a.member_code.compare(b.member_code);
        }
        else if (sort == 10)
        {
            // Descending order based on member_code
            return b.member_code.compare(a.member_code);
        }
        else
        {
            // Invalid sort value
            return 0;
        }
    }
    void insertionSort(int sort)
    {
        if (front != NULL)
        {
            if (front->next != NULL)
            {
                order_node *sorted = NULL;
                order_node *current = front;

                while (current != NULL)
                {
                    order_node *next = current->next;

                    // Find the appropriate position to insert the current node in the sorted list
                    order_node *prevSorted = NULL;
                    order_node *temp = sorted;

                    while (temp != NULL && compare(temp->data, current->data, sort) < 0)
                    {
                        prevSorted = temp;
                        temp = temp->next;
                    }

                    if (prevSorted == NULL)
                    {
                        // Insert at the beginning of the sorted list
                        current->next = sorted;
                        sorted = current;
                    }
                    else
                    {
                        // Insert in the middle or at the end of the sorted list
                        current->next = prevSorted->next;
                        prevSorted->next = current;
                    }

                    current = next;
                }

                front = sorted;
            }
        }
    }
    int calculateHashIndex(const string key)
    {
        int hashIndex = 0;
        int prime = 31;

        for (int i = 0; i < key.length(); i++)
        {
            hashIndex = (hashIndex * prime + key[i]) % 10;
        }

        return hashIndex;
    }
    void init_hashtable(int type)
    {
        for (int i = 0; i < 10; i++)
        {
            order_node *current = hashTable[i];
            while (current != NULL)
            {
                order_node *temp = current;
                current = current->next;
                delete temp;
            }
            hashTable[i] = NULL;
        }

        order_node *current = front;
        while (current != NULL)
        {
            string key;
            if (type == 1)
            {
                key = current->data.trans_code;
            }
            else if (type == 2)
            {
                key = current->data.order_at;
            }
            else if (type == 3)
            {
                key = current->data.total_price;
            }
            else if (type == 4)
            {
                key = current->data.member_code;
            }

            int hashIndex = calculateHashIndex(key);

            order_node *newNode = new order_node;
            newNode->data = current->data;
            newNode->next = NULL;

            if (hashTable[hashIndex] == NULL)
            {
                hashTable[hashIndex] = newNode;
            }
            else
            {
                order_node *temp = hashTable[hashIndex];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            current = current->next;
        }
    }

    order_node *hashing_search(int type, string keyword)
    {
        int hashIndex = calculateHashIndex(keyword);
        order_node *resultList = NULL;
        order_node *resultListTail = NULL;

        order_node *current = hashTable[hashIndex];
        while (current != NULL)
        {
            if (type == 1)
            {
                if (current->data.trans_code == keyword)
                {
                    order_node *newNode = new order_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 2)
            {
                if (current->data.order_at == keyword)
                {
                    order_node *newNode = new order_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 3)
            {
                if (current->data.total_price == string_to_float(keyword))
                {
                    order_node *newNode = new order_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }
            else if (type == 4)
            {
                if (current->data.member_code == keyword)
                {
                    order_node *newNode = new order_node;
                    newNode->data = current->data;
                    newNode->next = NULL;

                    if (resultList == NULL)
                    {
                        resultList = newNode;
                        resultListTail = newNode;
                    }
                    else
                    {
                        resultListTail->next = newNode;
                        resultListTail = resultListTail->next;
                    }
                }
            }

            current = current->next;
        }

        return resultList;
    }
};

class orders : public order_details
{
    order_queue order;

public:
    orders()
    {
        init();
    }
    ~orders()
    {
        store_to_file();
    }
    void init()
    {
        fstream orders_file;
        orders_file.open("orders.txt", ios::in);

        order_struct c;

        while (orders_file >> c.index >> c.trans_code >> c.order_at >> c.total_price >> c.has_member >> c.member_name >> c.member_code)
        {
            c.trans_code = underscore_to_space(c.trans_code);
            c.order_at = underscore_to_space(c.order_at);
            c.member_name = underscore_to_space(c.member_name);
            c.member_code = underscore_to_space(c.member_code);
            if (!c.has_member)
            {
                c.member_name = " ";
                c.member_code = " ";
            }

            order.append(c);
        }
        orders_file.close();
    }
    void store_to_file()
    {
        order.insertionSort(1);
        fstream orders_file;
        orders_file.open("orders.txt", ios::out);

        while (!order.isEmpty())
        {
            order_struct c = order.serve();

            c.trans_code = space_to_underscore(c.trans_code);
            c.order_at = space_to_underscore(c.order_at);
            c.member_name = space_to_underscore(c.member_name);
            c.member_code = space_to_underscore(c.member_code);
            if (!c.has_member)
            {
                c.member_name = "_";
                c.member_code = "_";
            }
            orders_file << c.index << " " << c.trans_code << " " << c.order_at << " " << c.total_price << " " << c.has_member << " " << c.member_name << " " << c.member_code << endl;
        }
        orders_file.close();
    }
    void view_order(int index = 0)
    {
        string target;

        if (index == 0)
        {
            cout << "Please enter the index of the order to view or [0] to cancel : ";
            fflush(stdin);
            getline(cin, target);
            while (!int_validation(target, false, true, "0", int_to_string(order.get_total_item())))
            {
                cout << "Invalid input, Please re-enter the index of the order to view or [0] to cancel : ";
                fflush(stdin);
                getline(cin, target);
            }
        }
        else
        {
            target = int_to_string(index);
        }

        if (target != "0" && target != "-1")
        {
            system("CLS");
            order_struct c = order.get_data_by_index(string_to_int(target));
            cout << endl;
            cout << fixed << setprecision(2);
            cout << "-----------------------------------------------------------------------------" << endl<< endl;
            cout << "                 \t    Receipt" << endl<< endl;
            cout << "-----------------------------------------------------------------------------" << endl<< endl;
            cout << "  Code          : " << c.trans_code << endl;
            cout << "  Date and Time : " << c.order_at << endl;
            cout << "  Member Name   : " << c.member_name << endl;
            cout << "  Member Code   : " << c.member_code << endl<< endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            display_order_detail(target);
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "Subtotal        : RM " << c.total_price << endl;
            if (c.has_member)
            {
                cout << "Discount Amount : RM " << (c.total_price * 0.05) << endl;
                cout << "Total Price     : RM " << (c.total_price * 0.95) << endl;
            }
            else
            {
                cout << "Discount Amount : RM 0.00" << endl;
                cout << "Total Price     : RM " << c.total_price << endl;
            }

            cout << endl << endl;
            system("pause");
        }
    }
    void create_order()
    {
        order_struct new_order;
        coffees *c = new coffees;
        order_detail_queue od;
        order_detail_struct new_order_detail;
        string coffees_id, qty, member_choice, member_code, do_continue;
        int i = 0;

        system("cls");
        if (c->get_coffee_count() != 0)
        {
            if (order.get_total_item() == 0)
            {
                new_order.trans_code = "00000001";
            }
            else
            {
                new_order.trans_code = "00000000";
                int int_trans_code = order.get_total_item() + 1;
                string code_modify = int_to_string(int_trans_code);
                int i = code_modify.length() - 1;
                int j = new_order.trans_code.length() - 1;
                while (i >= 0)
                {
                    new_order.trans_code[j] = code_modify[i];
                    i--;
                    j--;
                }
            }
            time_t rawtime;
            struct tm *timeinfo;
            char buffer[80];
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(buffer, 80, "%d-%m-%Y %I:%M.%p", timeinfo);
            new_order.order_at = buffer;
            new_order.index = order.get_total_item() + 1;

            do{
                i++;
                c->coffees_list();
                cout << endl
                     << "Please enter the Index of coffees you want : ";
                getline(cin, coffees_id);

                while (!int_validation(coffees_id, false, true, "1", int_to_string(c->get_coffee_count())))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Index of coffees you want : ";
                    getline(cin, coffees_id);
                }
                cout << "______________________________________________________________________________________" << endl
                     << endl;

                cout << "How many coffee you want to buy : ";
                getline(cin, qty);

                while (!int_validation(qty, false, true, "1", "50"))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the number of product you want to buy : ";
                    getline(cin, qty);
                }

                cout << endl;
                new_order_detail.index = get_order_detail_total_item() + i;
                new_order_detail.coffees_name = c->get_coffee_data_by_index(coffees_id).name;
                new_order_detail.coffees_sugar = c->get_coffee_data_by_index(coffees_id).sugar;
                new_order_detail.coffees_size = c->get_coffee_data_by_index(coffees_id).size;
                new_order_detail.qty = string_to_int(qty);
                new_order_detail.price = c->get_coffee_data_by_index(coffees_id).price;
                new_order_detail.total_price = new_order_detail.price * new_order_detail.qty;
                new_order_detail.orders_index = order.get_total_item() + 1;
                ;

                od.append(new_order_detail);

                cout << "Enter Y to continue placing the order. If not, press N :";
                getline(cin, do_continue);
                cout << endl;
            } while (do_continue == "Y" || do_continue == "y");

            cout << "Do you want to add your member code [Y/N] : ";
            getline(cin, member_choice);

            while (member_choice != "Y" && member_choice != "y" && member_choice != "N" && member_choice != "n")
            {
                fflush(stdin);
                cout << "Invalid input, Do you want to add your member code [Y/N] : ";
                getline(cin, member_choice);
            }

            if (member_choice == "Y" || member_choice == "y")
            {
                bool invalid_input = true;

                cout << "Please enter your Member Code : ";
                getline(cin, member_code);
                members *m = new members;

                while (m->find_member_by_code(member_code) == NULL)
                {
                    cout << "Invalid input, Please re-enter your Member Code : ";
                    getline(cin, member_code);
                }
                new_order.has_member = true;
                new_order.member_name = m->find_member_by_code(member_code)->data.name;
                new_order.member_code = m->find_member_by_code(member_code)->data.member_code;
            }
            else if (member_choice == "N" || member_choice == "n")
            {
                new_order.has_member = false;
                new_order.member_name = "_";
                new_order.member_code = "_";
            }
            create_order_detail(od.get_front_pointer());
            new_order.total_price = 0;
            while (!od.isEmpty())
            {
                order_detail_struct temp_order_detail = od.serve();
                new_order.total_price += temp_order_detail.total_price;
            }
            order.append(new_order);
        }
        else
        {
            cout << "No coffees Found ......" << endl
                 << endl;
            system("pause");
        }
        delete c;
    }
    int place_order()
    {
        order_struct new_order;
        coffees *s = new coffees;
        order_detail_queue od;
        order_detail_struct new_order_detail;
        string coffees_id, qty, member_choice, member_code, do_continue;
        int i = 0;

        system("cls");
        if (s->get_coffee_count() != 0)
        {
            if (order.get_total_item() == 0)
            {
                new_order.trans_code = "00000001";
            }
  	          else
            {
                new_order.trans_code = "00000000";
                int int_trans_code = order.get_total_item() + 1;
                string code_modify = int_to_string(int_trans_code);
                int i = code_modify.length() - 1;
                int j = new_order.trans_code.length() - 1;
                while (i >= 0)
                {
                    new_order.trans_code[j] = code_modify[i];
                    i--;
                    j--;
                }
            }
            time_t rawtime;
            struct tm *timeinfo;
            char buffer[80];
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(buffer, 80, "%d-%m-%Y %I:%M.%p", timeinfo);
            new_order.order_at = buffer;
            new_order.index = order.get_total_item() + 1;

            do
            {
                i++;
                s->coffees_list();
                cout << "Please enter the Index of coffees you want : ";
                getline(cin, coffees_id);

                while (!int_validation(coffees_id, false, true, "1", int_to_string(s->get_coffee_count())))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the Index of coffees you want : ";
                    getline(cin, coffees_id);
                }
                cout << "______________________________________________________________________________________" << endl
                     << endl;

                cout << "How many quantity you want to buy : ";
                getline(cin, qty);

                while (!int_validation(qty, false, true, "1", "50"))
                {
                    fflush(stdin);
                    cout << "Invalid input, Please re-enter the number of coffee you want to buy : ";
                    getline(cin, qty);
                }

                cout << endl;
                new_order_detail.index = get_order_detail_total_item() + i;
                new_order_detail.coffees_name = s->get_coffee_data_by_index(coffees_id).name;
                new_order_detail.coffees_sugar = s->get_coffee_data_by_index(coffees_id).sugar;
                new_order_detail.coffees_size = s->get_coffee_data_by_index(coffees_id).size;
                new_order_detail.qty = string_to_int(qty);
                new_order_detail.price = s->get_coffee_data_by_index(coffees_id).price;
                new_order_detail.total_price = new_order_detail.price * new_order_detail.qty;
                new_order_detail.orders_index = order.get_total_item() + 1;
                ;

                od.append(new_order_detail);

                cout << "Enter Y to continue placing the order. If not, press N :";
                getline(cin, do_continue);
            } while (do_continue == "Y" || do_continue == "y");

            cout << "Do you want to add your member code [Y/N] : ";
            getline(cin, member_choice);

            while (member_choice != "Y" && member_choice != "y" && member_choice != "N" && member_choice != "n")
            {
                fflush(stdin);
                cout << "Invalid input, Do you want to add your member code [Y/N] : ";
                getline(cin, member_choice);
            }

            if (member_choice == "Y" || member_choice == "y")
            {
                bool invalid_input = true;

                cout << "Please enter your Member Code : ";
                getline(cin, member_code);
                members *m = new members;

                while (m->find_member_by_code(member_code) == NULL)
                {
                    cout << "Invalid input, Please re-enter your Member Code : ";
                    getline(cin, member_code);
                }
                new_order.has_member = true;
                new_order.member_name = m->find_member_by_code(member_code)->data.name;
                new_order.member_code = m->find_member_by_code(member_code)->data.member_code;
            }
            else if (member_choice == "N" || member_choice == "n")
            {
                new_order.has_member = false;
                new_order.member_name = "_";
                new_order.member_code = "_";
            }
            create_order_detail(od.get_front_pointer());
            new_order.total_price = 0;
            while (!od.isEmpty())
            {
                order_detail_struct temp_order_detail = od.serve();
                new_order.total_price += temp_order_detail.total_price;
            }
            order.append(new_order);

            delete s;
            return new_order.index;
        }
        else
        {
            cout << "No coffees Found ......" << endl
                 << endl;
            system("pause");
            delete s;
            return -1;
        }
    }
    void orders_list(string criteria = "", string keyword = "", string sort = "1")
    {
        if (sort == "1" || sort == "")
        {
            order.insertionSort(1);
        }
        else if (sort == "2")
        {
            order.insertionSort(2);
        }
        else if (sort == "3")
        {
            order.insertionSort(3);
        }
        else if (sort == "4")
        {
            order.insertionSort(4);
        }
        else if (sort == "5")
        {
            order.insertionSort(5);
        }
        else if (sort == "6")
        {
            order.insertionSort(6);
        }
        else if (sort == "7")
        {
            order.insertionSort(7);
        }
        else if (sort == "8")
        {
            order.insertionSort(8);
        }
        else if (sort == "9")
        {
            order.insertionSort(9);
        }
        else if (sort == "10")
        {
            order.insertionSort(10);
        }

        order_node *temp = NULL;
        if (criteria == "")
        {
            temp = order.get_front_pointer();
        }
        else
        {
            if (criteria == "trans_code")
            {
                order.init_hashtable(1);
                temp = order.hashing_search(1, keyword);
            }
            else if (criteria == "order_at")
            {
                order.init_hashtable(2);
                temp = order.hashing_search(2, keyword);
            }
            else if (criteria == "total_price")
            {
                order.init_hashtable(3);
                temp = order.hashing_search(3, keyword);
            }
            else if (criteria == "member_code")
            {
                order.init_hashtable(4);
                temp = order.hashing_search(4, keyword);
            }
        }

        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(5) << left << "Index"
             << "|" << setw(20) << "Trasaction Code"
             << "|" << setw(20) << right << "Order At"
             << "|" << setw(20) << "Total Price"
             << "|" << setw(20) << left << "Member Code"
             << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        if (temp == NULL)
        {
            cout << "|                                       No Data Found                                     |" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << fixed << setprecision(2);

                stringstream ss;
                if (temp->data.has_member)
                {
                    ss << fixed << setprecision(2) << "RM " << (temp->data.total_price * 0.95);
                }
                else
                {
                    ss << fixed << setprecision(2) << "RM " << temp->data.total_price;
                }

                cout << "|" << setw(5) << left << temp->data.index << "|" << setw(20) << temp->data.trans_code << "|" << setw(20) << right << temp->data.order_at << "|" << setw(20) << ss.str() << "|" << setw(20) << left << temp->data.member_code << "|" << endl;
                temp = temp->next;
            }
        }
        
        cout << "-------------------------------------------------------------------------------------------" << endl;
    }
};

void orders_index()
{
    string criteria = "", keyword = "", option, sort = "1";
    bool repeat = true;
    do
    {
        orders *a = new orders;

        system("CLS");
        a->orders_list(criteria, keyword, sort);
        cout << endl;
        cout << "    Action" << endl;
        cout << "--------------" << endl;
        cout << "[1] Add orders" << endl;
        cout << "[2] View orders" << endl;
        cout << "[3] Search by Trasaction Code" << endl;
        cout << "[4] Search by Order At" << endl;
        cout << "[5] Search by Total Price" << endl;
        cout << "[6] Search by Member Code" << endl;
        cout << "[7] Reset Search" << endl;
        cout << "[8] Sort the List" << endl;
        cout << "[0] Back" << endl;
        cout << "Choose an action : ";
        fflush(stdin);
        getline(cin, option);
        while (!int_validation(option, false, true, "0", "8"))
        {
            cout << "Invalid input, Choose an action : ";
            fflush(stdin);
            getline(cin, option);
        }

        if (option == "1")
        {
            a->create_order();
        }
        else if (option == "2")
        {
            a->view_order();
        }
        else if (option == "3")
        {
            criteria = "trans_code";
            cout << "\nEnter Trasaction Code : ";
            fflush(stdin);
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Trasaction Code : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "4")
        {
            criteria = "order_at";
            cout << "\nEnter Order At : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Order At : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "5")
        {
            criteria = "total_price";
            cout << "\nEnter Total Price : RM ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Total Price : RM ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "6")
        {
            criteria = "member_code";
            cout << "\nEnter Member Code : ";
            getline(cin, keyword);
            while (!no_null_validation(keyword))
            {
                cout << "Invalid input, Enter Member Code : ";
                fflush(stdin);
                getline(cin, keyword);
            }
        }
        else if (option == "7")
        {
            criteria = "";
            keyword = "";
        }
        else if (option == "8")
        {
            cout << endl;
            cout << "[1] By Index Ascending" << endl;
            cout << "[2] By Index Descending" << endl;
            cout << "[3] By Trasaction Code Ascending" << endl;
            cout << "[4] By Trasaction Code Descending" << endl;
            cout << "[5] By Order At Ascending" << endl;
            cout << "[6] By Order At Descending" << endl;
            cout << "[7] By Total Price Ascending" << endl;
            cout << "[8] By Total Price Descending" << endl;
            cout << "[9] By Member Code Ascending" << endl;
            cout << "[10] By Member Code Descending" << endl;

            cout << "Sort list by : ";
            fflush(stdin);
            getline(cin, sort);
            while (!int_validation(sort, false, true, "1", "10"))
            {
                cout << "Invalid input, Sort list by : ";
                fflush(stdin);
                getline(cin, sort);
            }
        }
        else if (option == "0")
        {
            repeat = false;
        }
        else
        {
            cout << "Something went wrong";
        }

        delete a;
    } while (repeat);
}

void admin_dashboard(int admin_index)
{
    admins *a = new admins;
    system("cls");
    cout << "*****************************************" << endl;
    cout << "             Welcome, " << a->get_admin_data_by_index(admin_index).name << "." << endl;
    cout << "*****************************************" << endl;
    cout << "             Admin Dashboard" << endl;
    cout << "*****************************************" << endl;
    cout << "  Press 1 for Admin operation" << endl;
    cout << "  Press 2 for User operation" << endl;
    cout << "  Press 3 for Member operation" << endl;
    cout << "  Press 4 for Category operation" << endl;
    cout << "  Press 5 for Coffee operation" << endl;
    cout << "  Press 6 for Order operation" << endl;
    cout << "  Press 7 for Logout" << endl;
    cout << "*****************************************" << endl;
    delete a;
}

void user_dashboard(int user_index)
{
    users *s = new users;
    system("cls");
    cout << "*****************************************" << endl<< endl;
    cout << "             Welcome, " << s->get_user_data_by_index(user_index).name << "." << endl<< endl;
    cout << "*****************************************" << endl<< endl;
    cout << "             User Dashboard" << endl<< endl;
    cout << "*****************************************" << endl<< endl;
    cout << "  Press 1 for Place Order" << endl;
    cout << "  Press 2 for Edit Profile" << endl;
    cout << "  Press 3 for Register Member" << endl;
    cout << "  Press 4 for Logout" << endl<< endl;
    cout << "*****************************************" << endl;
    delete s;
}

void display_admin_dashboard(int admin_index)
{
    bool repeat_admin_dashboard = true;
    string admin_dashboard_choice;

    do
    {
        admin_dashboard(admin_index);
        cout << "Please enter your choice : ";
        getline(cin, admin_dashboard_choice);

        while (!int_validation(admin_dashboard_choice, false, true, "1", "7"))
        {
            admin_dashboard(admin_index);
            fflush(stdin);
            cout << "Invalid input, Please re-enter your choice : ";
            getline(cin, admin_dashboard_choice);
        }

        if (admin_dashboard_choice == "1")
        {
            admins_index();
        }
        else if (admin_dashboard_choice == "2")
        {
            users_index();
        }
        else if (admin_dashboard_choice == "3")
        {
            members_index();
        }
        else if (admin_dashboard_choice == "4")
        {
            categories_index();
        }
        else if (admin_dashboard_choice == "5")
        {
            coffees_index();
        }
        else if (admin_dashboard_choice == "6")
        {
            orders_index();
        }
        else if (admin_dashboard_choice == "7")
        {
            repeat_admin_dashboard = false;
        }
    } while (repeat_admin_dashboard);
}

void display_user_dashboard(int user_index)
{
    bool repeat_user_dashboard = true;
    string user_dashboard_choice;

    do
    {
        user_dashboard(user_index);
        cout << "Please enter your choice : ";
        getline(cin, user_dashboard_choice);

        while (!int_validation(user_dashboard_choice, false, true, "1", "4"))
        {
            user_dashboard(user_index);
            fflush(stdin);
            cout << "Invalid input, Please re-enter your choice : ";
            getline(cin, user_dashboard_choice);
        }

        if (user_dashboard_choice == "1")
        {
            orders *o = new orders;
            int order_index = o->place_order();
            cout << order_index;
            o->view_order(order_index);
            delete o;
        }
        else if (user_dashboard_choice == "2")
        {
            users *s = new users;
            s->edit_user(user_index);
            delete s;
        }
        else if (user_dashboard_choice == "3")
        {
            members *m = new members;
            m->create_member();
            delete m;
        }
        else if (user_dashboard_choice == "4")
        {
            repeat_user_dashboard = false;
        }
    } while (repeat_user_dashboard);
}

void user_login_menu()
{
    system("cls");
    cout << "*****************************************\n"<< endl;
	cout << "             User Login Menu            \n"<< endl;
	cout << "*****************************************\n"<< endl;
	cout << "   1. Login\n";
	cout << "   2. Back to main menu\n";
	cout << "   3. Exit\n"<< endl;
	cout << "*****************************************\n";

}

void admin_login_menu()
{
    system("cls");
    cout << "*****************************************" << endl<< endl;
    cout << "             Admin Login Menu            " << endl<< endl;
    cout << "*****************************************" << endl<< endl;
    cout << "   1.Login" << endl;
    cout << "   2.Back to main menu" << endl;
    cout << "   3.Exit" << endl<< endl;
    cout << "*****************************************" << endl;
}

void main_menu()
{
    system("cls");
    cout << "*****************************************" << endl<< endl;
    cout << "                Main Menu" << endl<< endl;
    cout << "*****************************************" << endl<< endl;
    cout << "   1.User Login" << endl;
    cout << "   2.Admin Login" << endl;
    cout << "   3.Exit" << endl<< endl;
    cout << "*****************************************" << endl;
}

void display_main_menu()
{
    string main_menu_choice;
    bool repeat_main_menu = true;

    do
    {
        main_menu();
        cout << "Please enter your choice : ";
        getline(cin, main_menu_choice);

        while (main_menu_choice != "1" && main_menu_choice != "2" && main_menu_choice != "3")
        {
            main_menu();
            fflush(stdin);
            cout << "Invalid input, Please re-enter your choice : ";
            getline(cin, main_menu_choice);
        }

        if (main_menu_choice == "1")
        {
            string user_login_choice;
            user_login_menu();
            cout << "Please enter your choice : ";
            getline(cin, user_login_choice);
            fflush(stdin);
            while (user_login_choice != "1" && user_login_choice != "2" && user_login_choice != "3")
            {
                user_login_menu();
                fflush(stdin);
                cout << "Invalid input, Please re-enter your choice : ";
                getline(cin, user_login_choice);
            }

            if (user_login_choice == "1")
            {
                string username, password, user_try_again_choice;
                int user_index = -1;

                do
                {
                    system("cls");
                    cout << "*****************************************" << endl<< endl;
                    cout << "               User Login" << endl<< endl;
                    cout << "*****************************************" << endl<< endl;
                    cout << "Please enter your Username : ";
                    getline(cin, username);
                    cout << "Please enter your Password : ";
                    getline(cin, password);

                    users *c = new users;
                    user_node *temp = c->find_user_data_by_username(username);
                    if (temp != NULL)
                    {
                        if (temp->data.password == password)
                        {
                            user_index = temp->data.index;
                            user_try_again_choice = "n";
                        }
                        else
                        {
                            cout << "Login failed. Enter Y to try again : ";
                            getline(cin, user_try_again_choice);
                        }
                    }
                    else
                    {
                        cout << "Login failed. Enter Y to try again : ";
                        getline(cin, user_try_again_choice);
                    }
                    delete c;
                } while (user_try_again_choice == "Y" || user_try_again_choice == "y");

                if (user_index != -1)
                {
                    display_user_dashboard(user_index);
                }
            }
            else if (user_login_choice == "3")
            {
                exit(0);
            }
        }
        else if (main_menu_choice == "2")
        {
            string admin_login_choice;
            admin_login_menu();
            cout << "Please enter your choice : ";
            getline(cin, admin_login_choice);
            fflush(stdin);
            while (admin_login_choice != "1" && admin_login_choice != "2" && admin_login_choice != "3")
            {
                admin_login_menu();
                fflush(stdin);
                cout << "Invalid input, Please re-enter your choice : ";
                getline(cin, admin_login_choice);
            }

            if (admin_login_choice == "1")
            {
                string username, password, admin_try_again_choice;
                int admin_index = -1;
                do
                {
                    system("cls");
                    cout << "*****************************************" << endl<< endl;
                    cout << "               Admin Login" << endl<< endl;
                    cout << "*****************************************" << endl<< endl;
                    cout << "Please enter your Username : ";
                    getline(cin, username);
                    cout << "Please enter your Password : ";
                    getline(cin, password);

                    admins *a = new admins;
                    admin_node *temp = a->find_admin_data_by_username(username);

                    if (temp != NULL)
                    {
                        if (temp->data.password == password)
                        {
                            admin_index = temp->data.index;
                            admin_try_again_choice = "n";
                        }
                        else
                        {
                            cout << "Login failed. Enter Y to try again : ";
                            getline(cin, admin_try_again_choice);
                        }
                    }
                    else
                    {
                        cout << "Login failed. Enter Y to try again : ";
                        getline(cin, admin_try_again_choice);
                    }
                    delete a;
                } while (admin_try_again_choice == "Y" || admin_try_again_choice == "y");

                if (admin_index != -1)
                {
                    display_admin_dashboard(admin_index);
                }
            }
            else if (admin_login_choice == "3")
            {
                exit(0);
            }
        }
        else if (main_menu_choice == "3")
        {
            exit(0);
        }
    } while (repeat_main_menu);
}

int main()
{
    display_main_menu();
    return 0;
}

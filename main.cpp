#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>

#include <fstream>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

int main() {
    BST bst;
    SplayTree splay_tree;
    RBTree rb_tree;

    string is1d1 = "data/data/insert/set1/data_1.txt";
    string is1d2 = "data/data/insert/set1/data_2.txt";
    string is1d3 = "data/data/insert/set1/data_3.txt";
    string is2d1 = "data/data/insert/set2/data_1.txt";
    string is2d2 = "data/data/insert/set2/data_2.txt";
    string is2d3 = "data/data/insert/set2/data_3.txt";

    string ss1d1 = "data/data/search/set1/data_1.txt";
    string ss1d2 = "data/data/search/set1/data_2.txt";
    string ss1d3 = "data/data/search/set1/data_3.txt";
    string ss2d1 = "data/data/search/set2/data_1.txt";
    string ss2d2 = "data/data/search/set2/data_2.txt";
    string ss2d3 = "data/data/search/set2/data_3.txt";

    string ds1d1 = "data/data/delete/set1/data_1.txt";
    string ds1d2 = "data/data/delete/set1/data_2.txt";
    string ds1d3 = "data/data/delete/set1/data_3.txt";
    string ds2d1 = "data/data/delete/set2/data_1.txt";
    string ds2d2 = "data/data/delete/set2/data_2.txt";
    string ds2d3 = "data/data/delete/set2/data_3.txt";

    string current_insert_file = is1d1;
    string current_search_file = ss1d1;
    string current_delete_file = ds1d1;

    /*
    ====================================================================BST====================================================================
    */
    ifstream insert_file(current_insert_file);
    ifstream search_file(current_search_file);
    ifstream delete_file(current_delete_file);

    if (!insert_file.is_open()) {
        std::cerr << "Unable to open insert file\n";
        return 1;
    }

    if (!search_file.is_open()) {
        std::cerr << "Unable to open search file\n";
        return 1;
    }

    if (!delete_file.is_open()) {
        std::cerr << "Unable to open delete file\n";
        return 1;
    }

    /*
    =============Insertion===============
    */
    string line;
    auto bst_insertion_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;
        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            bst.put(number, number);
        }

    }
    insert_file.close();
    
    auto bst_insertion_end_time = chrono::high_resolution_clock::now();
    auto bst_insertion_duration_cast = chrono::duration_cast<chrono::microseconds>(bst_insertion_end_time - bst_insertion_start_time);

    /*
    =============Search===============
    */
    // ifstream data_file(current_search_file);

    auto bst_search_start_time = chrono::high_resolution_clock::now();
    
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;
        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            cout << "BST Search number is: " << number << endl;
            bst.contains(number);
        }
    }
    search_file.close();
    auto bst_search_end_time = chrono::high_resolution_clock::now();
    auto bst_search_duration_cast = chrono::duration_cast<chrono::microseconds>(bst_search_end_time - bst_search_start_time);

    /*
    =============Deletion===============
    */
    auto bst_delete_start_time = chrono::high_resolution_clock::now();
    // insert_file.open(current_delete_file);
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;
        
        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            bst.del(number);
        }
    }
    delete_file.close();
    auto bst_delete_end_time = chrono::high_resolution_clock::now();
    auto bst_delete_duration_cast = chrono::duration_cast<chrono::microseconds>(bst_delete_end_time - bst_delete_start_time);


    /*
    ====================================================================Splay====================================================================
    */

   /*
    =============Insertion===============
    */
    insert_file.open(current_insert_file);

    auto splay_tree_insertion_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;

        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            splay_tree.put(number, number);
        }
    }

    insert_file.close();
    
    auto splay_tree_insertion_end_time = chrono::high_resolution_clock::now();
    auto splay_tree_insertion_duration_cast = chrono::duration_cast<chrono::microseconds>(splay_tree_insertion_end_time - splay_tree_insertion_start_time);

    /*
    =============Search===============
    */
    search_file.open(current_search_file);

    auto splay_tree_search_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;

        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            splay_tree.contains(number);
        }
    }

    search_file.close();
    
    auto splay_tree_search_end_time = chrono::high_resolution_clock::now();
    auto splay_tree_search_duration_cast = chrono::duration_cast<chrono::microseconds>(splay_tree_search_end_time - splay_tree_search_start_time);

    /*
    =============Deletion===============
    */
    delete_file.open(current_delete_file);

    auto splay_tree_delete_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;

        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            splay_tree.contains(number);
        }
    }

    delete_file.close();
    
    auto splay_tree_delete_end_time = chrono::high_resolution_clock::now();
    auto splay_tree_delete_duration_cast = chrono::duration_cast<chrono::microseconds>(splay_tree_delete_end_time - splay_tree_delete_start_time);
    

    /*
    ====================================================================RB====================================================================
    */

   /*
    =============Insertion===============
    */
    insert_file.open(current_insert_file);

    auto rb_tree_insert_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;

        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            rb_tree.put(number, number);
        }
    }

    insert_file.close();
    
    auto rb_tree_insert_end_time = chrono::high_resolution_clock::now();
    auto rb_tree_insert_duration_cast = chrono::duration_cast<chrono::microseconds>(rb_tree_insert_end_time - rb_tree_insert_start_time);

    /*
    =============Search===============
    */
    search_file.open(current_search_file);

    auto rb_tree_search_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;

        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            rb_tree.put(number, number);
        }
    }

    search_file.close();
    
    auto rb_tree_search_end_time = chrono::high_resolution_clock::now();
    auto rb_tree_search_duration_cast = chrono::duration_cast<chrono::microseconds>(rb_tree_search_end_time - rb_tree_search_start_time);

    /*
    =============Delete===============
    */
    delete_file.open(current_delete_file);

    auto rb_tree_delete_start_time = chrono::high_resolution_clock::now();
    while (getline(insert_file, line))
    {
        stringstream next_line(line);
        string value;

        while (getline(next_line, value, ','))
        {
            long long int number = stoll(value);
            rb_tree.put(number, number);
        }
    }

    delete_file.close();
    
    auto rb_tree_delete_end_time = chrono::high_resolution_clock::now();
    auto rb_tree_delete_duration_cast = chrono::duration_cast<chrono::microseconds>(rb_tree_delete_end_time - rb_tree_delete_start_time);

    cout << "BST insertion time: " << bst_insertion_duration_cast.count() << " in microseconds " << endl;
    cout << "BST search time: " << bst_search_duration_cast.count() << " in microseconds " << endl;
    cout << "BST deletion time: " << bst_delete_duration_cast.count() << " in microseconds " << endl;
    cout << endl;
    cout << "Splay Tree insertion time: " << splay_tree_insertion_duration_cast.count() << " in microseconds " << endl;
    cout << "Splay Tree search time: " << splay_tree_search_duration_cast.count() << " in microseconds " << endl;
    cout << "Splay Tree deletion time: " << splay_tree_delete_duration_cast.count() << " in microseconds " << endl;
    cout << endl;
    cout << "RB Tree insertion time: " << rb_tree_insert_duration_cast.count() << " in microseconds " << endl;
    cout << "RB Tree search time: " << rb_tree_search_duration_cast.count() << " in microseconds " << endl;
    cout << "RB Tree deletion time: " << rb_tree_delete_duration_cast.count() << " in microseconds " << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

struct Node{
	int znachenie;
	Node *next;
};

void zapolnenie(int chisla[], int count_chisla, Node **first, Node **last) {
	for(int i = 0; i < count_chisla; i++) {
		Node *node = new Node{chisla[i], nullptr};
		if((*last) == nullptr){
			(*last) = node;
			(*first) = (*last);
			continue;
		}
		(*last) -> next = node;
		(*last) = node;
	}
}

void FuncN1(Node *first){
	Node *curr = first;
	do{
		cout << curr -> znachenie;
		if (curr -> next != nullptr) cout << " -> ";
		curr = curr -> next;
	} 
	while (curr != nullptr);
	cout << endl;
}

int main(int argc, char *argv[]){
	int count_chisla = 0;
	int chisla[10];
	Node *last=nullptr;
	Node *first=nullptr;
	bool flag_chisla = false, flag_total = true;

	if (argc == 1){
		cout << "EMPTY LIST" << endl;
		flag_total = false;
	}
	for (int i = 0; i < 10; i++){
		chisla[i] = 0;
	}
	if (argc == 2){
		for (int i = 0; i < strlen(argv[1]); i++){
			if ((argv[1][i] >= '0') && (argv[1][i] <= '9')){
				if (flag_chisla = false){
					chisla[count_chisla] = argv[1][i] - 48;
				}
				else{
					chisla[count_chisla] = chisla[count_chisla] * 10 + argv[1][i] - 48;
				}
				if (argv[1][i + 1] == ','){
					count_chisla++;
					flag_chisla = false;
				}
				else{
					flag_chisla = true;
				}
			}
		}
		count_chisla++;
	}
	if (argc > 2){
		for (int i = 1; i < argc; i++){
			for (int k = 0; k < strlen(argv[i]); k++){
				if ((argv[i][k] >= '0') && (argv[i][k] <= '9')){
					if (flag_chisla = false){
						chisla[count_chisla] = argv[i][k] - 48;
					}
					else{
						chisla[count_chisla] = chisla[count_chisla] * 10 + argv[i][k] - 48;
					}
					if ((argv[i][k + 1] == ',') || (k + 1 == strlen(argv[i]))){
						count_chisla++;
						flag_chisla = false;
					}
					else{
						flag_chisla = true;
					}
				}
			}
		}
	}
	//запись чисел в массив
	
	zapolnenie(chisla, count_chisla, &first, &last);
	int ch = 0;
	string ch_exit = "";
	while ((ch_exit != "y") && (ch_exit != "yes") && (ch_exit != "Y") && (ch_exit != "Yes") && (ch_exit != "YES")){		
		while (ch != 7){
			if (flag_total == false) break;
			else{
				cout << endl;
   				cout << "Select operation:" << endl;
    				cout << "1.Print list" << endl;
    				cout << "2.Add elements to the list" << endl;
    				cout << "3.Delete element" << endl;
    				cout << "4.Find positions of elements" << endl;
    				cout << "5.Replace the element on the other" << endl;
    				cout << "6.Sort the list of elements" << endl;
    				cout << "7.Close program" << endl;
    				cin >> ch;
				switch(ch){
					case 1:
						FuncN1(first);
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						cout<<"Do you want to exit?" << endl;
						cin >> ch_exit;
						if ((ch_exit == "n") || (ch_exit == "no") || (ch_exit == "N") || (ch_exit == "No") || (ch_exit == "NO")){
							ch = 0;
							break;
						}
						if ((ch_exit == "y") || (ch_exit == "yes") || (ch_exit == "Y") || (ch_exit == "Yes") || (ch_exit == "YES")) cout << "Good Bye" << endl;
				}
			}
				
  		}
	}
}

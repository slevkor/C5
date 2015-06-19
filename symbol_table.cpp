#include <iostream>
#include <string>
#include <set>
#include <stack>
#include "symbol_table.hpp"

using std::string;
using std::set;

using namespace std;

int index = 0;

//**************** symbol_table methods *************
symbol_table::symbol_table() :
		table(set<elem>()) {
}

void symbol_table::insert_scope() {
	index++;
}

void symbol_table::delete_scope() {
	set<elem> newTable;
	set<elem>::iterator i;
	for (i = table.begin(); i != table.end(); i++) {
		if (i->data.scope != index) {
			newTable.insert(*i);
		}
	}
	table = newTable;
	if (index != 0){
		index--;
	}
}

bool symbol_table::is_element_in_table(const string& name) {
	tuple newTuple(name, index);
	if (table.find(elem(newTuple, "", "")) != table.end()) {
		return true;
	}
	return false;
}

void symbol_table::insert_element(const string& name, const string& type,
		const string& value) {
	tuple newTuple(name, index);
	elem newElement(newTuple, type, value);
	table.insert(newElement);
}

void symbol_table::delete_element(const string& name) {
	tuple newTuple(name, index);
	table.erase(elem(newTuple, "", ""));
}

bool symbol_table::is_element_in_scope(const string& name, int scope) {
	set<elem>::iterator i;
	for (i = table.begin(); i != table.end(); i++) {
		if ((i->data.scope == scope) && (i->data.name == name)) {
			return true;
		}
	}
	return false;
}

string symbol_table::get_type_of_element(const string& name) {
	int temp_index = index;
	while (temp_index >= 0) {
		tuple newTuple(name, temp_index);
		set<elem>::iterator newElement = table.find(elem(newTuple, "", ""));
		if (newElement != table.end()) {
			return newElement->type;
		}
		temp_index--;
	}
	return "";
}

string symbol_table::get_value_of_element(const string& name) {
	int temp_index = index;
	while (temp_index >= 0) {
		tuple newTuple(name, temp_index);
		set<elem>::iterator newElement = table.find(elem(newTuple, "", ""));
		if (newElement != table.end()) {
			return newElement->value;
		}
		temp_index--;
	}
	return "";
}

void symbol_table::set_type_and_value_of_element(const string& name,
		const string& type, string value) {
	int tempIndex = index;
	while (tempIndex >= 0) {
		tuple tempTuple(name, tempIndex);
		set<elem>::iterator tempElement = table.find(elem(tempTuple, "", ""));
		if (tempElement != table.end()) {
			tuple newTuple(name, tempElement->data.scope);
			delete_element(name);
			elem newElement(newTuple, type, value);
			table.insert(newElement);
			return;
		}
		tempIndex--;
	}
}


void symbol_table::print_scope(symbol_table st, int scope){
	cout << "elem in scope " << scope << "\n" <<endl;
	set<elem>::iterator i;
	for (i = st.table.begin(); i != st.table.end(); i++) {
		if (i->data.scope == scope) {
			cout << i->data.name << " " << i->type << " " << i->value << " \n" << endl;
		}
	}
	cout << "\n" <<endl;
}
#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <set>
#include <vector>
#include <list>

using std::string;
using std::set;
using std::list;

class tuple {
public:
	string name;
	int scope;

	tuple(string name1, int scope1) :
			name(name1), scope(scope1) {
	}
	;
};

class elem {
public:
	tuple data;
	string type;
	string value;
	string place;

	elem(tuple data1, string type1, string value1, string place1) :
			data(data1), type(type1), value(value1), place(place1) {
	}
	;

	bool operator<(const elem& obj) const {
		if (data.name == obj.data.name) {
			return data.scope < obj.data.scope;
		}
		return data.name < obj.data.name;
	}

	int get_scope(const elem& obj) {
		return obj.data.scope;
	}
};

class symbol_table {
public:
	set<elem> table;

	symbol_table();

	void insert_scope();
	void delete_scope();

	bool is_element_in_scope(const string& name, int scope);
	bool is_element_in_table(const string& name);
	void insert_element(const string& name, const string& type,
			const string& value, string place);
	void delete_element(const string& name, int scope);

	string get_place(const string& name);
	int get_index(string place);
	string get_type_of_element(const string& name);
	string get_value_of_element(const string& name);
	void set_type_and_value_of_element(const string& name, const string& type,
			string value, string place);

	void print_scope(symbol_table st, int scope);

};

#endif /* SYMBOL_TABLE_H_ */

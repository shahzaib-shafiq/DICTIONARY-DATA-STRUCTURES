#include "Hash.h"
#include "string"
ofstream out;

Hash::Hash()
{
	initTable();
	fstream fi("dictionary.txt");
	//reading file
	if (fi.is_open()) {
		string line;
		Word* w = new Word;
		TYPE* t = new TYPE;
		Meaning* m = new Meaning;
		while (getline(fi, line)) 
		{
			if (line[0] == '@' ) 
			{
				if (w->word.compare("") != 0) 
				{
					t->meanings.push_back(m);
					addType(w, t);
					addTable(w);
					w = new Word;
					t = new TYPE;
					m = new Meaning;
				}
				w = createWord(line.substr(1));
			}
			if (line[0] == '*') 
			{
				t = createType(line.substr(1));
				w->type = t;
			}
			if (line[0] == '-')
			{
				if (m->def.compare("") != 0) t->meanings.push_back(m);
				m = createMeaning(line.substr(1));
			}
			if (line[0] == '=')
			{
				string substr = line.substr(1);
				addExam(m, substr);
			}
		}
		if (w->word != "") 
		{
			t->meanings.push_back(m);
			addType(w, t);
			addTable(w);
		}
	}
}
int Hash::HashFunc(string key)
{
	int convert = 0;
	for (int i = 0; i < key.size(); i++) 
	{
		convert = (convert * base + key[i]) % MOD;
	}
	return convert;
}
void Hash::initTable()
{
	for (int i = 0; i < MOD; i++) {
		Hashtable[i] = new Doublelist;
	}
}
Word* Hash::createWord(string word)
{
		Word* p = new Word;
		if (!p) return NULL;
		p->next = p->pre = NULL;
		p->word = word;
		return p;
}
Word* Hash::createWord(string word, TYPE* type)
{
		Word* w = new Word;
		if (!w) return NULL;
		w->word = word;
		w->type = type;
		w->next = w->pre = NULL;
		return w;
	
}
TYPE* Hash::createType(string type_name)
{
	TYPE* t = new TYPE;
	if (!t) return NULL;
	t->type_name = type_name;
	return t;
}
void Hash::addMeaning(TYPE*& type, Meaning* m)
{
	type->meanings.push_back(m);
}
Meaning* Hash::createMeaning(string def)
{
	Meaning* m = new Meaning;
	if (!m) return NULL;
	m->def = def;
	return m;
}
void Hash::addExam(Meaning*& m, string exam)
{
	m->example.push_back(exam);
}
void Hash::addType(Word*& w, TYPE* type)
{
	w->type = type;
}
bool Hash::mila(string word)
{
	string temp1, temp2, at = "@",temp3;
	temp1 = word;
	temp2 = at.append(temp1);
	bool mila = true;
	fstream file("dictionary.txt", ios::in);
	while (!file.eof())
	{
		file >> temp3;
		if (temp3 == temp2)
		{
			mila = false;
		}
	}
	file.close();
	return mila;
}
bool Hash::space(string word)
{
	bool mila = true;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == ' ')
		{
			mila=false;
		}
	}
	return mila;
}
void Hash::addWord()
{
	if (out.is_open())
	{
		string word, type, def, exam, temp1, at = "@", temp2, temp3;
		cout << "\nWord: ";
		getline(cin, word);
		out.open("dictionary.txt", ios::out | ios::app);
		out << "\n@" << word;
		cout << "\nType: ";
		getline(cin, type);
		out << "\n*" << type;
		TYPE* t = this->createType(type);
		char k, j;
		do {
			cout << "\nDefinition: ";
			getline(cin, def);
			out << "\n-" << def;
			Meaning* m = this->createMeaning(def);
			do {
				cout << "\nExample: ";
				getline(cin, exam);
				out << "\n=" << exam;
				this->addExam(m, exam);
				cout << "\nType ` to continue, else exit ";
				j = _getch();
			} while (j == '`');
			this->addMeaning(t, m);
			cout << "\nType ` to continue, else exit ";
			k = _getch();
		} while (k == '`');
		Word* w = this->createWord(word, t);
		this->addTable(w);
	}
}
void Hash::addTable(Word* w)
{
	int key = HashFunc(w->word);
	if (Hashtable[key]->head == NULL) {
		Hashtable[key]->head = Hashtable[key]->tail = w;
	}
	else {
		Hashtable[key]->tail->next = w;
		w->pre = Hashtable[key]->tail;
		Hashtable[key]->tail = w;
	}
}
bool Hash::deleteWord(string word)
{
	int index = HashFunc(word);
	int flat = 0;
	Word* p = Hashtable[index]->head;
	while (p) {
		if (p->word.compare(word) == 0) {
			if (p == Hashtable[index]->head) {
				if (p == Hashtable[index]->tail)
				{
					Hashtable[index]->head = Hashtable[index]->tail = NULL;
					delete p;
					flat = 1;
					break;
				}
				else {
					Hashtable[index]->head = p->next;
					delete p;
					flat = 1;
					break;
				}
			}
			else if (p == Hashtable[index]->tail) {
				if (p != Hashtable[index]->head) {
					Hashtable[index]->tail = p->pre;
					p = NULL;
					flat = 1;
					break;
				}
			}
			else {
				p->pre->next = p->next;
				p->next->pre = p->pre;
				delete p;
				flat = 1;
				break;
			}
		}
		p = p->next;
	}
	if (flat) {
		return true;
	}
	return false;
}
bool Hash::editWord(Word* w)
{
	int flat = 0;
	int index = HashFunc(w->word);
	Word* p = Hashtable[index]->head;
	while (p) {
		if (p->word.compare(w->word) == 0) {
			p->type = w->type;
			flat = 1;
			break;
		}
		p = p->next;
	}
	if (flat) {
		updateFile();
		return true;
	}
	return false;
}
void Hash::showTable()
{
	for (int i = 0; i < MOD; i++) {
		Word* p = Hashtable[i]->head;
		while (p != NULL) {
			cout << "\n@" << p->word;
			cout << "\n*" << p->type->type_name;
			for (int j = 0; j < p->type->meanings.size(); j++) {
				cout << "\n-" << p->type->meanings[j]->def;
				for (int k = 0; k < p->type->meanings[j]->example.size(); k++) {
					cout << "\n=" << p->type->meanings[j]->example[k];
				}
			}
			p = p->next;
		}
	}
}
void Hash::updateFile()
{

	out.open("dictionary.txt",ios::out);
	if (out.is_open()) {
		for (int i = 0; i < MOD; i++) {
			Word* p = Hashtable[i]->head;
			while (p) {
				out << "\n@" << p->word;
				out << "\n*" << p->type->type_name;
				for (int j = 0; j < p->type->meanings.size(); j++) {
					out << "\n-" << p->type->meanings[j]->def;
					for (int k = 0; k < p->type->meanings[j]->example.size(); k++) {
						out << "\n=" << p->type->meanings[j]->example[k];
					}
				}
				p = p->next;
			}
		}
	}
	out.close();
}
void Hash::showWord(Word* p)
{
	cout << "\n" << p->word;
	cout << "\n" << p->type->type_name;
	for (int i = 0; i < p->type->meanings.size(); i++) {
		cout << "\n" << p->type->meanings[i]->def;
		for (int j = 0; j < p->type->meanings[i]->example.size(); j++) {
			cout << "\n" << p->type->meanings[i]->example[j];
		}
	}
}

Word* Hash::Search(string key)
{
	int index = HashFunc(key);
	for (int i = 0; i < MOD; i++) {
		Word* p = Hashtable[i]->head;
		while (p) {
			if (p->word.compare(key) == 0) {
				return p;
			}
			p = p->next;
		}
	}
	return NULL;
}

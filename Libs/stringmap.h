#ifndef _stringmap_h
#define _stringmap_h

using namespace std;
class StringMap{
	
public:

StringMap();
~StringMap();

string get(const string & key) const;
//uso: string value = map.get(key);

void put(const string & key, const string & value);
//uso: map.put(key, value);

//private:

};

#endif
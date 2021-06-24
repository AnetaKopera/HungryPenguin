#ifndef _fieldh_
#define _fieldh_

class Field
{
protected:
	bool status;
public:
	Field();
	Field(const Field& f);
	Field& operator =(const Field& f);
	virtual ~Field() {}
	void setIceFloe();
	bool getInformation();
};


#endif
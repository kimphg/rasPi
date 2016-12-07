
#ifndef CONFIG_H
#define CONFIG_H

#define SCALE_MAX 80
#define SCALE_MIN 5

#define CFG_FILE_NAME    "phase_config.xml"
#define DEFAULT_LAT		20.707f
#define DEFAULT_LONG	106.78f
#define LAT_MIN			5
#define LAT_MAX			25
#define LON_MIN		105
#define LON_MAX		125
#include <QFile>
#include <QTextStream>
#include <string>
#include <tinyxml/tinyxml2.h>
struct phase_item
{
    double freg;
    double phaseChanel[8];
};

class CConfig
{

public:
	
	CConfig(void);
	~CConfig(void);
	void SaveToFile();
	void setDefault();
    bool LoadFromFile();

    void addItem(phase_item *item);
    phase_item getItem(int index) const;
    int getItemListSize();
    void sortItems();
    void clearItem();
    double getValue(double freq, int chanel);
private:
    QList <phase_item> itemList;
};
#endif


#include "c_config.h"

 
CConfig::CConfig(void)
{
    setDefault();
    LoadFromFile();
}

CConfig::~CConfig(void)
{
}
void CConfig::addItem(phase_item* item)
{
    itemList.push_back(*item);
    //SaveToFile();

}
void CConfig::clearItem()
{
    itemList.clear();

}
phase_item CConfig::getItem(int index) const
{
    return itemList.at(index);
}
void CConfig::sortItems()
{
    for(int i=0;i<itemList.size();i++)
    {
        for(int j=i+1;j<itemList.size();j++)
        {
            if(itemList.at(i).freg>itemList.at(j).freg)
            {
               phase_item temp = itemList[i];
               itemList[i] = itemList[j];
               itemList[j] = temp;
            }
        }
    }
}
int CConfig::getItemListSize()
{
    return itemList.size();
}
void CConfig::SaveToFile()
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement * phase_config ;
    for (int i=0; i< itemList.size();i++)
    {
        phase_config = doc.NewElement("phase_config");
        doc.LinkEndChild(phase_config);
        phase_config->SetAttribute("frequency",itemList.at(i).freg);
        phase_config->SetAttribute("ch1",itemList.at(i).phaseChanel[0]);
        phase_config->SetAttribute("ch2",itemList.at(i).phaseChanel[1]);
        phase_config->SetAttribute("ch3",itemList.at(i).phaseChanel[2]);
        phase_config->SetAttribute("ch4",itemList.at(i).phaseChanel[3]);
        phase_config->SetAttribute("ch5",itemList.at(i).phaseChanel[4]);
        phase_config->SetAttribute("ch6",itemList.at(i).phaseChanel[5]);
        phase_config->SetAttribute("ch7",itemList.at(i).phaseChanel[6]);
        phase_config->SetAttribute("ch8",itemList.at(i).phaseChanel[7]);

    }

    doc.SaveFile(CFG_FILE_NAME);

}


void CConfig::setDefault()
{
	//m_config.comPort.Empty();
    //m_config.comRate    = 4800;
//    mLat      = DEFAULT_LAT;//20.8;20.705434, 106.785371
//    mLon      = DEFAULT_LONG;//106.87;
//    scale      = SCALE_MIN;
//    trueN      = 0;
//    dxView     = 0;
//    dyView     = 0;
//    mapEnabled = false;
//    cfarThresh = 15;
//    codeType   = 0;
//    socket_port_arpa = 8800;
//    socket_port_radar =8900;
//    this->mapFilename = "outputmap4layer.ism";
    SaveToFile();
	//m_config.mapFilename.Empty();
	
}


bool CConfig::LoadFromFile()
{
    tinyxml2::XMLDocument xmlDoc;
    if(xmlDoc.LoadFile(CFG_FILE_NAME)==0)
    {
        //TiXmlHandle hDoc(&doc);
        tinyxml2::XMLElement  *pParm;

        pParm = xmlDoc.FirstChildElement("phase_config");
        while(pParm)
        {

           phase_item item;
           pParm->QueryDoubleAttribute("frequency",&item.freg);
           pParm->QueryDoubleAttribute("ch1",&item.phaseChanel[0]);
           pParm->QueryDoubleAttribute("ch2",&item.phaseChanel[1]);
           pParm->QueryDoubleAttribute("ch3",&item.phaseChanel[2]);
           pParm->QueryDoubleAttribute("ch4",&item.phaseChanel[3]);
           pParm->QueryDoubleAttribute("ch5",&item.phaseChanel[4]);
           pParm->QueryDoubleAttribute("ch6",&item.phaseChanel[5]);
           pParm->QueryDoubleAttribute("ch7",&item.phaseChanel[6]);
           pParm->QueryDoubleAttribute("ch8",&item.phaseChanel[7]);
           this->itemList.push_back(item);
           pParm=pParm->NextSiblingElement() ;

        }
//        pParm->QueryDoubleAttribute("mLat",&mLat);
//        pParm->QueryDoubleAttribute("mLong",&mLon);
//        pParm->QueryDoubleAttribute("scale",&scale);
//        pParm->QueryDoubleAttribute("trueN",&trueN);
//        const char *pName=pParm->Attribute("mapFilename");
//        if(pName)mapFilename.append(pName);
        return true;
    }
    else
    {
        printf("Could not load config file.");
        //setDefault();
        return false;
    }
    /*
    QFile file(CFG_FILE);
    if(!file.open(QIODevice::ReadOnly))
    {
        setDefault();
        return false;
    }
    QTextStream in(&file);
    QString line = in.readLine();// map file
    m_config.mapFilename = line.toStdString();
    line = in.readLine();//coordinate lat
    m_config.m_lat = line.toDouble();
    line = in.readLine();//coordinate long
    m_config.m_long = line.toDouble();
    line = in.readLine();// last scale NIM
    m_config.scale = line.toDouble();
    line = in.readLine();// true north
    m_config.trueN = line.toDouble();
    line = in.readLine();// dx NIM
    m_config.dxView = line.toDouble();
    line = in.readLine();//dy NIM
    m_config.dyView = line.toDouble();
    line = in.readLine();// enable map
    m_config.mapEnabled = line.toInt();
    line = in.readLine();// CFAR thresh
    m_config.cfarThresh = line.toInt();
    if((m_config.cfarThresh>40)||(m_config.cfarThresh<0))
    {
        m_config.cfarThresh = 30;
    }
    line = in.readLine();// modulation code
    m_config.codeType = line.toInt();
    file.close();
    return true;*/
}


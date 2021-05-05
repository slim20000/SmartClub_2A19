#include "arduino.h"

arduino::arduino()
{
 data="";
 arduino_prot_name="";
 arduino_is_available=false;
 serial=new QSerialPort;
}

QString arduino::getarduino_port_name()
{
    return arduino_prot_name;
}

QSerialPort* arduino::getserial()
{
    return serial;
}

int arduino::connect_arduino()
{
foreach(const QSerialPortInfo& serial_port_info,QSerialPortInfo::availablePorts())
{
    if(serial_port_info.hasVendorIdentifier() && QSerialPortInfo.hasProductIdentifier()==arduino_uno_product_id)
    {
        arduino_is_available=true;
        arduino_prot_name=serial_port_info.portName();
    }
}
QDebug() <<"arduino port name:" << arduino_prot_name;
if(arduino_is_available)
{
    serial->setPortName(arduino_prot_name);
    if(serial->open(QSerialPort::ReadWrite))
    {
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        Serial->setFlowControl(QSerialPort::noFlowControl);
        return 0;
    }
    return 1;
}
return -1;
}

int arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}

int arduino::write_to_arduino(QByteArray d)
if(serial->iswritable())
{
    serial->write(d);
}
else
qDebug() <<"erreur en ecriture";
}

QByteArray arduino::read_from_arduino()
{
//    int digitalPin = 4;
//    int analogPin = A0; // KY-026 analog interface
//    int digitalVal; // digital readings
//    int analogVal; //analog readings

//    void setup()
//    {
//    pinMode(digitalPin, OUTPUT);
//    digitalWrite(digitalPin, LOW);
//    }

//    void loop()
//    {
//    // Read the analog interface
//    analogVal = analogRead(analogPin);
//    if (analogVal<=11){ // le capteur KY-026 détecte un feu
//    digitalWrite(digitalPin, HIGH); // LED s’allume et le buzzer sonne
//    } else { // sinon
//    digitalWrite(digitalPin, LOW); // LED s’éteint et le buzzer s’arrête de sonner
//    }
//    delay(100);
//    }
    if(serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
}


#include "dialog.h"

#include <QApplication>
#include <QDebug>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

int main(int argc, char *argv[])
{
    int row, col;
    QString str;
    QDateTime current_date_time;
    QApplication a(argc, argv);

    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");  // write "Hello Qt!" to cell(A,1). it's shared string.
    xlsx.write(2, 1, "Hello World!");
    xlsx.saveAs("Test.xlsx");       // save the document as 'Test.xlsx'
    QVariant data = xlsx.read("A1");
    qDebug() << data.type() << data.toString();
    data = xlsx.read(2, 1);
    qDebug() << data.type() << data.toString();


    // 写入测试
    QXlsx::Document xlsx1("Test.xlsx");
    // 记录开始时间
    current_date_time =QDateTime::currentDateTime();
    qDebug() << "test time     " << current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
    current_date_time =QDateTime::currentDateTime();
    qDebug() << "start time    " << current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
    for(row = 1; row <= 10000; row++) {
        for(col = 1; col <= 100; col++) {
            xlsx1.write(row, col, "Hello World!");
        }
    }
    current_date_time =QDateTime::currentDateTime();
    qDebug() << "write end time" << current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
    // 保存测试
    xlsx1.save();
    current_date_time =QDateTime::currentDateTime();
    qDebug() << "save end time " << current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");

    // 读取测试
    QXlsx::Document xlsx2("Test.xlsx");
    current_date_time =QDateTime::currentDateTime();
    qDebug() << "read start time" << current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
    for(row = 1; row <= 10000; row++) {
        for(col = 1; col <= 100; col++) {
            xlsx2.read(row, col);
        }
    }
    current_date_time =QDateTime::currentDateTime();
    qDebug() << "read end time  " << current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");

    Dialog w;
    w.show();
    return a.exec();
}

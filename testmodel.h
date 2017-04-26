#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QStringListModel>
#include <QStringList>


class TestModel : public QStringListModel
{
public:
    TestModel();
private:
    QStringList *slTest;
    int loadTests();
};

#endif // TESTMODEL_H

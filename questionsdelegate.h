#ifndef QUESTIONSDELEGATE_H
#define QUESTIONSDELEGATE_H

#include <QObject>
#include <QSqlRelationalDelegate>

class QuestionsDelegate : public QSqlRelationalDelegate
{
public:
    explicit QuestionsDelegate(int testId, QObject *aParent);
    QWidget *createEditor(QWidget *aParent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    explicit QuestionsDelegate(QObject *aParent);
    int testId;

public:
    void setTestId(int _n_testId);
};

#endif // QUESTIONSDELEGATE_H

#ifndef QUESTIONSDELEGATE_H
#define QUESTIONSDELEGATE_H

#include <QObject>
#include <QSqlRelationalDelegate>

class QuestionsDelegate : public QSqlRelationalDelegate
{
public:
    explicit QuestionsDelegate(QObject *aParent);
    QWidget *createEditor(QWidget *aParent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // QUESTIONSDELEGATE_H

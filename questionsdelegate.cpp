#include "questionsdelegate.h"

QuestionsDelegate::QuestionsDelegate(QObject *aParent = 0) : QSqlRelationalDelegate(aParent) {

}

QWidget *QuestionsDelegate::createEditor(QWidget *aParent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    const QSqlRelationalTableModel *sqlModel = qobject_cast<const QSqlRelationalTableModel *>(index.model());
    QSqlTableModel *childModel = sqlModel ? sqlModel->relationModel(index.column()) : 0;
    if (!childModel)
        return QItemDelegate::createEditor(aParent, option, index);

    //set filter and update data
    childModel->setFilter("qtype_ticket_type=2");
    childModel->select();

    QComboBox *combo = new QComboBox(aParent);
    combo->setModel(childModel);
    combo->setModelColumn(childModel->fieldIndex(sqlModel->relation(index.column()).displayColumn()));
    combo->installEventFilter(const_cast<QuestionsDelegate *>(this));

    return combo;
}

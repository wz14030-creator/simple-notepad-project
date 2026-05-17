#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QStringList>
#include <set>
#include <string>

class SpellChecker : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit SpellChecker(QTextDocument* document, const std::set<std::string>& dictionary);
    bool isMisspelled(const QString& word) const;
    QStringList getSuggestions(const QString& word, int maxSuggestions = 5) const;

protected:
    void highlightBlock(const QString& text) override;

private:
    const std::set<std::string>& m_dictionary;
    QTextCharFormat m_misspelledFormat;
};

#endif

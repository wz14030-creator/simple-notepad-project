#include "spell_checker.h"
#include <QRegularExpression>
#include <unordered_set>
#include <cctype>

SpellChecker::SpellChecker(QTextDocument* document, const std::set<std::string>& dictionary)
    : QSyntaxHighlighter(document)
      , m_dictionary(dictionary)
{
    m_misspelledFormat.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
    m_misspelledFormat.setUnderlineColor(Qt::red);
}

void SpellChecker::highlightBlock(const QString& text)
{
    static const QRegularExpression wordRegex("[A-Za-z]+");
    QRegularExpressionMatchIterator it = wordRegex.globalMatch(text);
    while (it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        QString word = match.captured(0);
        if (isMisspelled(word))
        {
            setFormat(match.capturedStart(), match.capturedLength(), m_misspelledFormat);
        }
    }
}

bool SpellChecker::isMisspelled(const QString& word) const
{
    std::string lowerWord = word.toLower().toStdString();
    return m_dictionary.find(lowerWord) == m_dictionary.end();
}

QStringList SpellChecker::getSuggestions(const QString& word, int maxSuggestions) const
{
    std::string original = word.toLower().toStdString();
    std::unordered_set<std::string> candidates;

    // 1. 删除一个字符
    for (size_t i = 0; i < original.size(); ++i)
    {
        std::string cand = original;
        cand.erase(i, 1);
        candidates.insert(cand);
    }
    // 2. 替换一个字符为 a-z
    for (size_t i = 0; i < original.size(); ++i)
    {
        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (c == original[i]) continue;
            std::string cand = original;
            cand[i] = c;
            candidates.insert(cand);
        }
    }
    // 3. 插入一个字符 a-z
    for (size_t i = 0; i <= original.size(); ++i)
    {
        for (char c = 'a'; c <= 'z'; ++c)
        {
            std::string cand = original;
            cand.insert(i, 1, c);
            candidates.insert(cand);
        }
    }
    // 4. 交换相邻字符
    for (size_t i = 0; i + 1 < original.size(); ++i)
    {
        std::string cand = original;
        std::swap(cand[i], cand[i + 1]);
        candidates.insert(cand);
    }

    QStringList suggestions;
    for (const auto& cand : candidates)
    {
        if (m_dictionary.find(cand) != m_dictionary.end())
        {
            suggestions << QString::fromStdString(cand);
            if (suggestions.size() >= static_cast<qsizetype>(maxSuggestions))
                break;
        }
    }
    return suggestions;
}

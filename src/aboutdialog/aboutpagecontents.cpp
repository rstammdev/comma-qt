/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/comma-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutpagecontents.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>


AboutPageGeneral::AboutPageGeneral(QWidget* parent)
    : AboutPage{parent}
{
    const QStringList paragraphs = {
        tr("Tabular files, also known as spreadsheet files, are digital data storage formats that organize information into rows and columns, similar to a traditional spreadsheet. They are commonly used for storing and managing data in a structured manner, making it easier to analyze, manipulate, and visualize."),
        tr("<a href=\"https://rstammdev.github.io/comma-qt\" title=\"Visit project's homepage\">Comma-Qt</a> is a free open-source application for viewing and editing these tabular files written in C++ using the Qt framework."),
        tr("Copyright &copy; 2025 <a href=\"%2\" title=\"Visit organization's homepage\">%1</a>.").arg(QApplication::organizationName(), QApplication::organizationDomain()),
        tr("This program is distributed under the terms of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.en.html\" title=\"Visit license's homepage\">GNU General Public License</a>, either version 3 of the License, or any later version.")
    };

    QString text;
    for (const QString& paragraph : paragraphs) {
        text += tr("<p>%1</p>\n").arg(paragraph);
    }

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);

    setPageTitle(tr("General"));
}

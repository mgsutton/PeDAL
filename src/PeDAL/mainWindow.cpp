////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright(c) 2019 Matt Sutton
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// summary:	Implements the mainWindow
////////////////////////////////////////////////////////////////////////////////
#include <QObject>
#include <QAction>
#include <QSplitter>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QPixmap>
#include <QSplitter>

#include "mainWindow.h"
#include <editorTabWidget.h>
#include <htmlTabWidget.h>

MainWindow::MainWindow(QWidget *pParent) : 
	QMainWindow(pParent),
	pNewFileAction(nullptr),
	pOpenFileAction(nullptr),
	pSaveFileAction(nullptr),
	pSaveFileAsAction(nullptr),
	pUndoAction(nullptr),
	pRedoAction(nullptr),
	pCutAction(nullptr),
	pCopyAction(nullptr),
	pPasteAction(nullptr),
	pPrintAction(nullptr)
{
	createLayout();
}

MainWindow::~MainWindow()
{}

///////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates the overall layout of the window </summary>
///
/// <remarks>	Sutton, 7/29/2019. </remarks>
///////////////////////////////////////////////////////////////////////////////

void MainWindow::createLayout()
{
	createActions();
	createToolbar();
	createMenubar();
	createCentralWidget();
}

void MainWindow::createActions()
{
	QString msg;

	pExitAction = new QAction(tr("E&xit"), this);
	pExitAction->setShortcut(QKeySequence::Quit);
	pExitAction->setStatusTip(tr("Exit PeDAL"));

	QIcon iconNewFile;
	iconNewFile.addPixmap(QPixmap(":/res/NewFile_16x.png"));
	pNewFileAction = new QAction(iconNewFile, tr("&New File"), this);
	pNewFileAction->setShortcut(QKeySequence::New);
	pNewFileAction->setStatusTip(tr("Create a new APDL macro file."));
	pNewFileAction->setToolTip(tr("New File"));

	QIcon iconOpenFile;
	iconOpenFile.addPixmap(QPixmap(":/res/OpenFile_16x.png"));
	pOpenFileAction = new QAction(iconOpenFile, tr("&Open"), this);
	pOpenFileAction->setShortcut(QKeySequence::Open);
	pOpenFileAction->setStatusTip(tr("Open and existing APDL macro file."));
	pOpenFileAction->setToolTip(tr("Open File"));

	QIcon iconSaveFile;
	iconSaveFile.addPixmap(QPixmap(":/res/Save_16x.png"));
	pSaveFileAction = new QAction(iconSaveFile, tr("&Save"), this);
	pSaveFileAction->setShortcut(QKeySequence::Save);
	pSaveFileAction->setStatusTip(tr("Save an APDL macro to disk."));
	pSaveFileAction->setToolTip(tr("Save File"));

	QIcon iconSaveFileAs;
	iconSaveFileAs.addPixmap(QPixmap(":/res/SaveAs_16x.png"));
	pSaveFileAsAction = new QAction(iconSaveFileAs, tr("Save As..."), this);
	pSaveFileAsAction->setShortcut(QKeySequence::SaveAs);
	msg = "Save an APDL macro to disk, potentially with a different file name.";
	pSaveFileAsAction->setStatusTip(msg);
	pSaveFileAsAction->setToolTip(tr("Save As..."));

	QIcon iconUndo;
	iconUndo.addPixmap(QPixmap(":/res/Undo_16x.png"));
	pUndoAction = new QAction(iconUndo, tr("Undo"), this);
	pUndoAction->setShortcut(QKeySequence::Undo);
	msg = "Undo the previous action.";
	pUndoAction->setStatusTip(msg);
	pUndoAction->setToolTip(tr("Undo"));

	QIcon iconRedo;
	iconRedo.addPixmap(QPixmap(":/res/Redo_16x.png"));
	pRedoAction = new QAction(iconRedo, tr("Redo"), this);
	pRedoAction->setShortcut(QKeySequence::Redo);
	msg = "Redo the previous action.";
	pRedoAction->setStatusTip(msg);
	pRedoAction->setToolTip(tr("Redo"));

	QIcon iconCut;
	iconCut.addPixmap(QPixmap(":/res/Cut_16x.png"));
	pCutAction = new QAction(iconCut, tr("Cut"), this);
	pCutAction->setShortcut(QKeySequence::Cut);
	msg = "Cut the current selection to the clipboard.";
	pCutAction->setStatusTip(msg);
	pCutAction->setToolTip(tr("Cut"));

	QIcon iconCopy;
	iconCopy.addPixmap(QPixmap(":/res/Copy_16x.png"));
	pCopyAction = new QAction(iconCopy, tr("Copy"), this);
	pCopyAction->setShortcut(QKeySequence::Copy);
	msg = "Copy the current selection to the clipboard.";
	pCopyAction->setStatusTip(msg);
	pCopyAction->setToolTip(tr("Copy"));

	QIcon iconPaste;
	iconPaste.addPixmap(QPixmap(":/res/Paste_16x.png"));
	pPasteAction = new QAction(iconPaste, tr("Paste"), this);
	pPasteAction->setShortcut(QKeySequence::Paste);
	msg = "Paste the contents of the clipboard at the cursor location.";
	pPasteAction->setStatusTip(msg);
	pPasteAction->setToolTip(tr("Paste"));

	QIcon iconPrint;
	iconPrint.addPixmap(QPixmap(":/res/Print_16x.png"));
	pPrintAction = new QAction(iconPrint, tr("Print"), this);
	pPrintAction->setShortcut(QKeySequence::Print);
	msg = "Print the current APDL macro file.";
	pPrintAction->setStatusTip(msg);
	pPrintAction->setToolTip(tr("Print"));
}

void MainWindow::assertActionsAreDefined()
{
	assert(pExitAction != nullptr);
	assert(pNewFileAction != nullptr);
	assert(pOpenFileAction != nullptr);
	assert(pSaveFileAction != nullptr);
	assert(pSaveFileAsAction != nullptr);
	assert(pUndoAction != nullptr);
	assert(pRedoAction != nullptr);
	assert(pCutAction != nullptr);
	assert(pPasteAction != nullptr);
	assert(pCopyAction != nullptr);
	assert(pPrintAction != nullptr);
}
void MainWindow::createToolbar()
{
	assertActionsAreDefined();
	pToolBar = new QToolBar(this);
	pToolBar->setMovable(false);
	pToolBar->setFloatable(false);

	pToolBar->addAction(pNewFileAction);
	pToolBar->addAction(pOpenFileAction);
	pToolBar->addAction(pSaveFileAction);
	pToolBar->addAction(pSaveFileAsAction);
	pToolBar->addSeparator();
	pToolBar->addAction(pPrintAction);
	pToolBar->addSeparator();
	pToolBar->addAction(pRedoAction);
	pToolBar->addAction(pUndoAction);
	pToolBar->addSeparator();
	pToolBar->addAction(pCutAction);
	pToolBar->addAction(pCopyAction);
	pToolBar->addAction(pPasteAction);

	addToolBar(pToolBar);
}

void MainWindow::createMenubar()
{
	assertActionsAreDefined();
	QMenu *pFileMenu = menuBar()->addMenu(tr("&File"));
	pFileMenu->addAction(pNewFileAction);
	pFileMenu->addAction(pOpenFileAction);
	pFileMenu->addAction(pSaveFileAction);
	pFileMenu->addAction(pSaveFileAsAction);
	pFileMenu->addSeparator();
	pFileMenu->addAction(pPrintAction);
	pFileMenu->addSeparator();
	pFileMenu->addAction(pExitAction);

	QMenu *pEditMenu = menuBar()->addMenu(tr("Edit"));
	pEditMenu->addAction(pRedoAction);
	pEditMenu->addAction(pUndoAction);
	pEditMenu->addSeparator();
	pEditMenu->addAction(pCutAction);
	pEditMenu->addAction(pCopyAction);
	pEditMenu->addAction(pPasteAction);
}

void MainWindow::createCentralWidget()
{
	QSplitter *pMainSplitter = new QSplitter(Qt::Orientation::Horizontal, this);
	pEditorTab = new EditorTabWidget(this);
	pHTMLTab = new HTMLTabWidget(this);
	pMainSplitter->addWidget(pEditorTab);
	pMainSplitter->addWidget(pHTMLTab);
	setCentralWidget(pMainSplitter);
}
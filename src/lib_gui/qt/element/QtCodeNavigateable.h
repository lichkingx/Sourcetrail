#ifndef QT_CODE_NAVIGATEABLE_H
#define QT_CODE_NAVIGATEABLE_H

#include <set>

#include "utility/file/FilePath.h"
#include "utility/TimePoint.h"
#include "utility/types.h"

#include "component/view/helper/CodeSnippetParams.h"

class QRectF;
class QAbstractScrollArea;
class QWidget;

class QtCodeNavigateable
{
public:
	virtual ~QtCodeNavigateable();

	virtual QAbstractScrollArea* getScrollArea() = 0;

	virtual void addCodeSnippet(const CodeSnippetParams& params, bool insert = false) = 0;

	virtual void requestFileContent(const FilePath& filePath) = 0;
	virtual bool requestScroll(const FilePath& filePath, uint lineNumber, Id locationId, bool animated, bool onTop) = 0;

	virtual void updateFiles() = 0;
	virtual void showContents() = 0;

	virtual void onWindowFocus() = 0;

protected:
	void ensureWidgetVisibleAnimated(QWidget* parentWidget, QWidget *childWidget, QRectF rect, bool animated, bool onTop);
	void ensurePercentVisibleAnimated(double percent, bool animated, bool onTop);
};

#endif // QT_CODE_NAVIGATEABLE_H
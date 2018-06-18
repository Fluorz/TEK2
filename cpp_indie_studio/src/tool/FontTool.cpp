/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** FontTool.cpp
*/

#include "FontTool.hpp"

FontTool &FontTool::getInstance()
{
	static FontTool instance;
	return instance;
}

irr::gui::IGUIFont *FontTool::getFont(const wchar_t *text, float rap,
				      bool Bold, FontSelectType type)
{
	auto &self = FontTool::getInstance();
	if (ECS::MComponent<CIrrMain>::getAll().empty())
		return nullptr;
	auto &env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto &driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;

	if (self.fontList.empty() && !Bold)
		return env->getBuiltInFont();

	const irr::core::dimension2du &s = driv->getScreenSize();

	auto it = self.fontList.begin();
	irr::gui::IGUIFont *font = nullptr;
	float diff = -1;
	float wantedSize = s.Width * rap;

	while (it != self.fontList.end()) {
		irr::gui::IGUIFont *curFont = *it;
		irr::core::dimension2d<irr::u32> curSize =
			curFont->getDimension(text);
		float curDiff = wantedSize - curSize.Width;

		if (diff != -1) {
			if (type == CLOSEST && ABS(diff) < ABS(curDiff))
				return font;
			if (type == CLOSEST_UP && curSize.Width > wantedSize)
				return curFont;
			if (type == CLOSEST_DOWN && curSize.Width > wantedSize)
				return font;
		}
		diff = wantedSize - curSize.Width;
		font = curFont;
		std::advance(it, 1);
	}
	return font;
}

static void empBackNoNull(std::vector<irr::gui::IGUIFont *> &list,
			  irr::gui::IGUIFont *font)
{
	if (font)
		list.push_back(font);
}

FontTool::FontTool()
{
	if (ECS::MComponent<CIrrMain>::getAll().empty())
		return;
	auto &env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;

	empBackNoNull(fontList, env->getFont("./media/font8px.xml"));
	empBackNoNull(fontList, env->getFont("./media/font12px.xml"));
	empBackNoNull(fontList, env->getFont("./media/font16px.xml"));
	empBackNoNull(fontList, env->getFont("./media/font22px.xml"));
	empBackNoNull(fontList, env->getFont("./media/font28px.xml"));
	empBackNoNull(fontList, env->getFont("./media/font36px.xml"));
	empBackNoNull(fontList, env->getFont("./media/font48px.xml"));
}

FontTool::~FontTool() {

}

void
FontTool::draw(const wchar_t *str, float rap, irr::core::vector2d<irr::s32> Pos,
	       irr::video::SColor color, DrawPosStart start, bool Bold,
	       FontSelectType type)
{
	auto &self = FontTool::getInstance();

	irr::gui::IGUIFont *font = FontTool::getFont(str, rap, Bold, type);
	irr::s32 x = start == CENTER ?
			Pos.X - font->getDimension(str).Width / 2 : Pos.X;
	irr::s32 y = Pos.Y;
	irr::s32 x2 = start == CENTER ?
			Pos.X + font->getDimension(str).Width / 2 :
			Pos.X + font->getDimension(str).Width;
	irr::s32 y2 = Pos.Y + font->getDimension(str).Height;
	font->draw(str, irr::core::rect<irr::s32>(x, y, x2, y2), color);
}

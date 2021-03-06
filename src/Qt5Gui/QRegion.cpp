#include "QRegion.hpp"

#include "../convert/callable.hpp"
#include "../thread.hpp"
#include "../Qt5Core/QRect.hpp"

int QRegion_contains(lua_State* const state)
{
    return 0;
}

int QRegion_intersected(lua_State* const state)
{
    return 0;
}

int QRegion_intersects(lua_State* const state)
{
    return 0;
}

int QRegion_rects(lua_State* const state)
{
    return 0;
}

int QRegion_setRects(lua_State* const state)
{
    return 0;
}

int QRegion_translate(lua_State* const state)
{
    return 0;
}

int QRegion_translated(lua_State* const state)
{
    return 0;
}

int QRegion_united(lua_State* const state)
{
    return 0;
}

void lua::QRegion_metatable(const lua::index& mt)
{
    mt["boundingRect"] = &QRegion::boundingRect;
    mt["contains"] = QRegion_contains;
    mt["intersected"] = QRegion_intersected;
    mt["intersects"] = QRegion_intersects;
    mt["isEmpty"] = &QRegion::isEmpty;
    mt["isNull"] = &QRegion::isNull;
    mt["rectCount"] = &QRegion::rectCount;
    mt["rects"] = QRegion_rects;
    mt["setRects"] = QRegion_setRects;
    mt["subtracted"] = &QRegion::subtracted;
    mt["swap"] = &QRegion::swap;
    mt["translate"] = QRegion_translate;
    mt["translated"] = QRegion_translated;
    mt["united"] = QRegion_united;
    mt["xored"] = &QRegion::xored;
}

int QRegion_new(lua_State* const state)
{
    lua::make<QRegion>(state);

    auto name = lua::class_name(lua::index(state, 2));
    if (name == lua::Metatable<QRect>::name) {
        if (lua_gettop(state) > 2) {
            lua::make<QRegion>(state,
                lua::get<QRect>(state, 2)
            );
        } else {
            lua::make<QRegion>(state, lua::get<QRect>(state, 2));
        }
    } else {
        lua::make<QRegion>(state);
    }
    return 1;
}

int luaopen_Qt5Gui_QRegion(lua_State* const state)
{
    lua::thread env(state);

    env["QRegion"] = lua::value::table;
    env["QRegion"]["new"] = QRegion_new;

    return 0;
}

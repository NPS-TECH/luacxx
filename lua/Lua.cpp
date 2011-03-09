#include "Lua.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>

using std::runtime_error;
using std::istream;

namespace {
	struct LuaReadingData
	{
		istream& stream;
		char buffer[4096];

		LuaReadingData(istream& stream) : stream(stream) {}
	};

	const char* read_stream(lua_State *L, void *data, size_t *size)
	{
		LuaReadingData* d = static_cast<LuaReadingData*>(data);
		if (!d->stream)
			return NULL;
		d->stream.read(d->buffer, 4096);
		*size = d->stream.gcount();
		return d->buffer;
	}
}


Lua::Lua()
{
	state = luaL_newstate();
	luaL_openlibs(state);
}

void Lua::operator()(istream& stream, const char* name = nullptr)
{
	LuaReadingData d(stream);
	if(0 != lua_load(state, &read_stream, &d, name)) {
		throw runtime_error(lua_tostring(state, -1));
	}
	lua_call(state, 0, 0);
}

void Lua::operator()(const string& input)
{
	std::istringstream stream(input);
	(*this)(stream, "string input");
}

LuaValue Lua::operator[](const string& key)
{
	return LuaValue(*this, key);
}

Lua::~Lua()
{
	lua_close(state);
}


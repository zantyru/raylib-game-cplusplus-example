#include <string>
#include "raylib.h"
#include "constants.hpp"
#include "library_of_textures.hpp"


namespace Example
{
	TextureLibrary::TextureLibrary()
	{
		for (int idx = 0; idx < TEXTURE_LIBRARY_CAPACITY; idx++)
		{
			this->_is_texture_loaded[idx] = false;
		}
	}

	TextureLibrary::~TextureLibrary()
	{
		for (int idx = 0; idx < TEXTURE_LIBRARY_CAPACITY; idx++)
		{
			if (this->_is_texture_loaded[idx])
			{
				::UnloadTexture(this->_textures[idx]);
			}
		}
	}

	void TextureLibrary::LoadTexture(const int& id, const std::string& filename)
	{
		// При некорректном id досрочный выход
		if (!this->_is_id_valid(id)) return;

		// Если файла не существует, то досрочный выход
		if (!::FileExists(filename.c_str())) return;

		// Если по указанному id уже загружена текстура, то выгружаем её
		this->UnloadTexture(id);

		// Загрузка
		this->_textures[id] = ::LoadTexture(filename.c_str());
		this->_is_texture_loaded[id] = true;
	}

	void TextureLibrary::UnloadTexture(const int& id)
	{
		// При некорректном id досрочный выход
		if (!this->_is_id_valid(id)) return;

		::UnloadTexture(this->_textures[id]);
		this->_is_texture_loaded[id] = false;
	}

	const Texture2D& TextureLibrary::GetTexture(const int& id) const
	{
		// При некорректном id возвращаем текстуру с id == 0
		if (!this->_is_id_valid(id)) return this->_textures[0];  //@THREAT Может быть не загружена текстура

		// Если текстура не загружена, то возвращаем текстуру с id == 0
		if (!this->_is_texture_loaded[id]) return this->_textures[0];  //@THREAT Может быть не загружена текстура

		return this->_textures[id];
	}

	bool TextureLibrary::_is_id_valid(const int& id) const
	{
		return id >= 0 && id < TEXTURE_LIBRARY_CAPACITY;
	}

}
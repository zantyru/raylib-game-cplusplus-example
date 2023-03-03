#include <string>
#include "raylib.h"
#include "constants.hpp"
#include "library_of_textures.hpp"


namespace Example
{
    TextureLibrary::TextureLibrary()
    {
        for (int idx = 0; idx < TextureLibrary::CAPACITY; idx++)
        {
            this->_is_texture_loaded[idx] = false;
        }
    }

    TextureLibrary::~TextureLibrary()
    {
        for (int idx = 0; idx < TextureLibrary::CAPACITY; idx++)
        {
            if (this->_is_texture_loaded[idx])
            {
                ::UnloadTexture(this->_textures[idx]);
            }
        }
    }

    void TextureLibrary::LoadTexture(const int& id, const std::string& filename)
    {
        // ��� ������������ id ��������� �����
        if (!this->_is_id_valid(id)) return;

        // ���� ����� �� ����������, �� ��������� �����
        if (!::FileExists(filename.c_str())) return;

        // ���� �� ���������� id ��� ��������� ��������, �� ��������� �
        this->UnloadTexture(id);

        // ��������
        this->_textures[id] = ::LoadTexture(filename.c_str());
        this->_is_texture_loaded[id] = true;
    }

    void TextureLibrary::UnloadTexture(const int& id)
    {
        // ��� ������������ id ��������� �����
        if (!this->_is_id_valid(id)) return;

        ::UnloadTexture(this->_textures[id]);
        this->_is_texture_loaded[id] = false;
    }

    const Texture2D& TextureLibrary::GetTexture(const int& id) const
    {
        // ��� ������������ id ���������� �������� � id == 0
        if (!this->_is_id_valid(id)) return this->_textures[0];  //@THREAT ����� ���� �� ��������� ��������

        // ���� �������� �� ���������, �� ���������� �������� � id == 0
        if (!this->_is_texture_loaded[id]) return this->_textures[0];  //@THREAT ����� ���� �� ��������� ��������

        return this->_textures[id];
    }

    bool TextureLibrary::_is_id_valid(const int& id) const
    {
        return id >= 0 && id < TextureLibrary::CAPACITY;
    }
}
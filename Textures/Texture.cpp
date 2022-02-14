#include "Texture.hpp"

Texture::Texture(void) {
}

Texture::Texture([[maybe_unused]]const Texture& t) {
}

Texture::~Texture(void) {
}

Texture& Texture::operator=(const Texture& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

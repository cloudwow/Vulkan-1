#include "BaseComponent.h"
#include <vector>
#include <memory>

template<typename COMPONENT>
struct ComponentAndId {
    unsigned long _entity_id;
    COMPONENT component;
};

template<typename COMPONENT>
class ComponentTable {
public:

    ComponentTable(std::size_t size)   {
      _components.reserve(size);
    }

    COMPONENT *createNew(unsigned long entity_id) {
    //  BaseComponent *component = new COMPONENT();
    //  (static_cast<COMPONENT *>(component))->Reset(std::forward<unsigned long>(entity_id));
    return NULL;
    }

private:
    std::size_t _size;
    std::vector<ComponentAndId<COMPONENT>> _components;
};

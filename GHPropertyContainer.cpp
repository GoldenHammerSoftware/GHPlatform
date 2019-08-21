// Copyright 2010 Golden Hammer Software
#include "GHPropertyContainer.h"

void GHPropertyContainer::setProperty(GHIdentifier type, const GHProperty& val)
{
    mProperties[type] = val;
}

const GHProperty& GHPropertyContainer::getProperty(const GHIdentifier& type) const
{
    PropertyMap::const_iterator findIter = mProperties.find(type);
    if (findIter == mProperties.end())
    {
		if (!mParentProperties)
		{
			return GHProperty::sInvalidProperty;
		}
		else
		{
			// recurse up the tree.
			return mParentProperties->getProperty(type);
		}
    }
    return findIter->second;
}

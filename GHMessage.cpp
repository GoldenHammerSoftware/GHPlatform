// Copyright 2010 Golden Hammer Software
#include "GHPlatform/GHMessage.h"

GHMessage::GHMessage(GHIdentifier type, GHPropertyContainer* data)
:	mMessageType(type)
{
    if (data) mPayload = *data;
}

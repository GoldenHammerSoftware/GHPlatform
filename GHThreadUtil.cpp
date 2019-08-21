// Copyright 2010 Golden Hammer Software
#include "GHThreadUtil.h"

#include "GHMessageTypes.h"
#include "GHBaseIdentifiers.h"
#include "GHMessage.h"
#include "GHMessageSenderTransition.h"
#include "GHTypedVoidFuncRunnable.h"

GHTransition* GHThreadUtil::createMessageWrapperTransition(GHTransition& targetTrans, GHMessageHandler& handler)
{
    GHTypedVoidFuncRunnable<GHTransition>* activateRunnable = new GHTypedVoidFuncRunnable<GHTransition>(targetTrans, &GHTransition::activate);
    GHMessage* activateMessage = new GHMessage(GHMessageTypes::EXECRUNNABLE);
    activateMessage->getPayload().setProperty(GHBaseIdentifiers::RUNNABLE,
                                              GHProperty(activateRunnable, new GHRefCountedType<GHTypedVoidFuncRunnable<GHTransition> >(activateRunnable)));
    
    GHTypedVoidFuncRunnable<GHTransition>* deactivateRunnable = new GHTypedVoidFuncRunnable<GHTransition>(targetTrans, &GHTransition::deactivate);
    GHMessage* deactivateMessage = new GHMessage(GHMessageTypes::EXECRUNNABLE);
    deactivateMessage->getPayload().setProperty(GHBaseIdentifiers::RUNNABLE,
                                                GHProperty(deactivateRunnable, new GHRefCountedType<GHTypedVoidFuncRunnable<GHTransition> >(deactivateRunnable)));
    
    GHMessageSenderTransition* ret = new GHMessageSenderTransition(handler);
    ret->addActivateMessage(activateMessage);
    ret->addDeactivateMessage(deactivateMessage);
    return ret;
}

/// MIT License, Copyright Burak Kara, burak@burak.io, https://en.wikipedia.org/wiki/MIT_License

#include "SBExtendedInputBox.h"
#include "Input/Events.h"
#include "Layout/Geometry.h"

FText SBExtendedInputBox::GetInputText() const
{
	return GetText();
}

void SBExtendedInputBox::SetInputText(FText InText)
{
	SetText(InText);
}

void SBExtendedInputBox::SetInputError(FString InError)
{
	SetError(InError);
}

void SBExtendedInputBox::SetInputSuggestions(TArray<FString> SuggestionStrings)
{
	SetSuggestions(SuggestionStrings, false);
}

void SBExtendedInputBox::ClearInputSuggestions()
{
	ClearSuggestions();
}

void SBExtendedInputBox::MarkActiveInputSuggestion()
{
	MarkActiveSuggestion();
}

FString SBExtendedInputBox::GetSelectedInputSuggestionString()
{
	return GetSelectedSuggestionString();
}

void SBExtendedInputBox::NavigateUp()
{
	FModifierKeysState keyState;
	FGeometry geom;
	FKeyEvent keyEvent(EKeys::Up, keyState, 0, false, 0, 0);
	OnKeyDown(geom, keyEvent);
}

void SBExtendedInputBox::NavigateDown()
{
	FModifierKeysState keyState;
	FGeometry geom;
	FKeyEvent keyEvent(EKeys::Down, keyState, 0, false, 0, 0);
	OnKeyDown(geom, keyEvent);
}

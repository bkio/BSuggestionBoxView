/// MIT License, Copyright Burak Kara, burak@burak.io, https://en.wikipedia.org/wiki/MIT_License

#include "BSuggestionInputBox.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "BSuggestionBoxView.h"

#define LOCTEXT_NAMESPACE "UMG"

UBSuggestionInputBox::UBSuggestionInputBox()
{
}

#if WITH_EDITOR
const FText UBSuggestionInputBox::GetPaletteCategory()
{
	return LOCTEXT("Input", "Input");
}
#endif

TSharedRef<SWidget> UBSuggestionInputBox::RebuildWidget()
{
	MySuggestionTextBlock = SNew(SBExtendedInputBox)
		.ClearKeyboardFocusOnCommit(false)
		.OnTextChanged(BIND_UOBJECT_DELEGATE(FOnTextChanged, HandleInputTextChanged))
		.OnTextCommitted(BIND_UOBJECT_DELEGATE(FOnTextCommitted, HandleInputTextCommitted))
		.OnShowingSuggestions(BIND_UOBJECT_DELEGATE(FOnShowingSuggestions, HandleInputTextShowingSuggestions))
		.BackgroundColor(BackgroundColor)
		.ForegroundColor(ForegroundColor)
		.Font(Font)
		.HintText(HintText)
		.MinDesiredWidth(MinDesiredWidth)
		.SuggestionListMaxHeight(SuggestionListMaxHeight)
		.Text(Text);

	return MySuggestionTextBlock.ToSharedRef();
}

#if WITH_ACCESSIBILITY
TSharedPtr<SWidget> UBSuggestionInputBox::GetAccessibleWidget() const
{
	return MySuggestionTextBlock;
}
#endif

FText UBSuggestionInputBox::GetText() const
{
	return MySuggestionTextBlock->GetText();
}

void UBSuggestionInputBox::SetText(FText InText)
{
	MySuggestionTextBlock->SetInputText(InText);
}

void UBSuggestionInputBox::SetError(FString InError)
{
	MySuggestionTextBlock->SetInputError(InError);
}

void UBSuggestionInputBox::SetSuggestions(TArray<FString> SuggestionStrings)
{
	MySuggestionTextBlock->SetInputSuggestions(SuggestionStrings);
}

void UBSuggestionInputBox::ClearSuggestions()
{
	MySuggestionTextBlock->ClearInputSuggestions();
}

void UBSuggestionInputBox::MarkActiveSuggestion() 
{
	MySuggestionTextBlock->MarkActiveInputSuggestion();
}

FString UBSuggestionInputBox::GetSelectedSuggestionString()
{
	return MySuggestionTextBlock->GetSelectedInputSuggestionString();
}

void UBSuggestionInputBox::HandleInputTextChanged(const FText& InText)
{
	OnTextChanged.Broadcast(InText);
}

void UBSuggestionInputBox::HandleInputTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	OnTextCommitted.Broadcast(InText, CommitInfo);
}

void UBSuggestionInputBox::HandleInputTextShowingSuggestions(const FString& InText, TArray<FString>& OutSuggestions)
{
	OnShowingSuggestions.Broadcast(InText, OutSuggestions);
}

void UBSuggestionInputBox::NavigateUp()
{
	MySuggestionTextBlock->NavigateUp();
}

void UBSuggestionInputBox::NavigateDown()
{
	MySuggestionTextBlock->NavigateDown();
}

bool UBSuggestionInputBox::HasSuggestionsOpen()
{
	return MySuggestionTextBlock->HasOpenPopup();
}
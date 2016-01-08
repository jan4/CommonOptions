#include "BaseOption.h"
#include "Section.h"

#include "OptionDescription.h"
#include "ParaType.h"

namespace commonOptions {

BaseOption::BaseOption(Section* _section, std::string const& _name, ParaType _paraType)
	: mSection (_section)
	, mName (_name)
	, mParaType (_paraType)
	, mOptionDescription ( nullptr )
{
}

BaseOption::~BaseOption() {

}

auto BaseOption::getSectionName() const -> std::string {
	return mSection->fullName();
}

auto BaseOption::getName() const -> std::string const& {
	return mName;
}
auto BaseOption::getParaType() const -> ParaType {
	return mParaType;
}
void BaseOption::createDescription(std::string const& _defaultValue, std::string const& _description) {
	//!TODO handling of changing default value or description
	mOptionDescription = mSection->getDescription(mName);
	if (mOptionDescription->description != "" and _description == ""
	    and mOptionDescription->description != _description) {
		throw std::runtime_error("description of option is being changed, not a good idea");
	}
	if (_description != "") {
		mOptionDescription->description = _description;
	}
	mOptionDescription->defaultValue = _defaultValue;
}


}

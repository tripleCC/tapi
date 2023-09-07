//===- tapi/Core/APIPrinter.h - TAPI API Printer ----------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Declares the TAPI API Printer
//===----------------------------------------------------------------------===//

#ifndef TAPI_CORE_APIPRINTER_H
#define TAPI_CORE_APIPRINTER_H

#include "tapi/Core/APIVisitor.h"

TAPI_NAMESPACE_INTERNAL_BEGIN

class APIPrinter : public APIVisitor {
public:
  APIPrinter(raw_ostream &os, bool useColor = true);
  ~APIPrinter() override;

  void visitMacroDefinition(const MacroDefinitionRecord &) override;
  void visitGlobal(const GlobalRecord &) override;
  void visitEnum(const EnumRecord &) override;
  void visitObjCInterface(const ObjCInterfaceRecord &) override;
  void visitObjCCategory(const ObjCCategoryRecord &) override;
  void visitObjCProtocol(const ObjCProtocolRecord &) override;
  void visitTypeDef(const TypedefRecord &) override;
  void visitStruct(const StructRecord &) override;

private:
  void printEnumConstant(const EnumConstantRecord *constant);
  void printMethod(const ObjCMethodRecord *method);
  void printProperty(const ObjCPropertyRecord *property);
  void printInstanceVariable(const ObjCInstanceVariableRecord *ivar);
  void printProtocol(SymbolInfo protocol);
  void printStructField(const StructFieldRecord *field);

  raw_ostream &os;
  bool hasColors = false;

  bool emittedHeaderMacro = false;
  bool emittedHeaderGlobal = false;
  bool emittedHeaderEnum = false;
  bool emittedHeaderInterface = false;
  bool emittedHeaderCategory = false;
  bool emittedHeaderProtocol = false;
  bool emittedHeaderTypedef = false;
  bool emittedHeaderStruct = false;
};

TAPI_NAMESPACE_INTERNAL_END

#endif // TAPI_CORE_APIPRINTER_H

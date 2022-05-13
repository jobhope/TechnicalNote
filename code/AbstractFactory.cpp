#include<memory>
#include<iostream>

class Document
{
public:
    virtual void PrintInfo() const = 0;
};

class DocumentFactory
{
public:
    virtual std::unique_ptr<Document> Create() final
    {
        return this->MakeFactory();
    }
    virtual std::unique_ptr<Document> MakeFactory() = 0;
};

class PDFDoc final : public Document
{
public:
    void PrintInfo() const override
    {
        std::cout << "PDF Document." << std::endl;
    }
};

class WordDoc final : public Document
{
public:
    void PrintInfo() const override
    {
        std::cout << "Word Document." << std::endl;
    }
};

class PDFDocFactory final : public DocumentFactory
{
public:
    virtual std::unique_ptr<Document> MakeFactory()
    {
        return std::make_unique<PDFDoc>();
    }
};

class WordDocFactory final : public DocumentFactory
{
public:
    virtual std::unique_ptr<Document> MakeFactory()
    {
        return std::make_unique<WordDoc>();
    }
};

int main() 
{
    std::unique_ptr<DocumentFactory> creator = std::make_unique<PDFDocFactory>();
    auto pdf = creator->Create();
    pdf->PrintInfo();

    creator.reset(new WordDocFactory);
    auto word = creator->Create();
    word->PrintInfo();

    return 0;
}
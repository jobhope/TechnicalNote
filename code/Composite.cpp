#include<algorithm>
#include<iostream>
#include<memory>
#include<string>
#include<vector>

class FileSystem
{
public:
    explicit FileSystem(std::string name) : name_(std::move(name)) {}
    virtual ~FileSystem() = default;

    virtual int GetSize() const = 0;

    virtual FileSystem* Add(std::unique_ptr<FileSystem>&& filesystem)
    {
        (void)filesystem;
        throw std::logic_error("Add() is not supported operation.");
    }
    virtual void Remove() = 0;

    std::string GetName() const { return name_; }

private:
    std::string name_;
};

class File : public FileSystem
{
public:
    File(std::string const& name, std::uint64_t size) : FileSystem(name), size_(size) {}

    int GetSize() const override
    {
        return size_;
    }

    void Remove() override
    {
        std::cout << GetName() << " 파일 삭제" << std::endl;
    }
private:
    int size_;
};

class Folder : public FileSystem
{
public:
    explicit Folder(const std::string& name) : FileSystem(name) {}

    int GetSize() const override
    {
        int total = 0u;
        for (auto const& included : includeds)
        {
            total += included->GetSize();
        }
        std::cout << GetName() << " 폴더 크기 : " << total << std::endl;
        std::cout << "- - - - -" << std::endl;
        return total;
    }

    FileSystem* Add(std::unique_ptr<FileSystem>&& data) override
    {
        includeds.push_back(std::move(data));
        return includeds.back().get();
    }

    void Remove() override
    {
        for (auto const& included : includeds)
        {
            included->Remove();
        }
        std::cout << GetName() << " 폴더 삭제" << std::endl;
        std::cout << "- - - - -" << std::endl;
    }

private:
    std::vector<std::unique_ptr<FileSystem>> includeds;
};

int main()
{
    auto schoolFolder = std::make_unique<Folder>("학교");
    auto grade1Folder = schoolFolder->Add(std::make_unique<Folder>("1학년"));
    auto grade2Folder = schoolFolder->Add(std::make_unique<Folder>("2학년"));

    auto enterPhoto = grade1Folder->Add(std::make_unique<File>("입학사진", 256));

    auto sem1Folder = grade2Folder->Add(std::make_unique<Folder>("1학기"));
    auto sem2Folder = grade2Folder->Add(std::make_unique<Folder>("2학기"));

    auto lecturePlan = sem1Folder->Add(std::make_unique<File>("강의계획서", 120));

    auto projectFolder = sem2Folder->Add(std::make_unique<Folder>("프로젝트"));

    auto draft = projectFolder->Add(std::make_unique<File>("드래프트", 488));
    auto finalResult = projectFolder->Add(std::make_unique<File>("결과물", 500));

    schoolFolder->GetSize();
    /*
        1학기 폴더 크기 : 120
        - - - - -
        프로젝트 폴더 크기 : 988
        - - - - -
        2학기 폴더 크기 : 988
        - - - - -
        2학년 폴더 크기 : 1108
        - - - - -
        학교 폴더 크기 : 1364
        - - - - -
    */
    schoolFolder->Remove();
    /*
        입학사진 파일 삭제
        1학년 폴더 삭제
        - - - - -
        강의계획서 파일 삭제
        1학기 폴더 삭제
        - - - - -
        드래프트 파일 삭제
        결과물 파일 삭제
        프로젝트 폴더 삭제
        - - - - -
        2학기 폴더 삭제
        - - - - -
        2학년 폴더 삭제
        - - - - -
        학교 폴더 삭제
        - - - - -
    */
    return 0;
}
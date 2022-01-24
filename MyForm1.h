#pragma once

#include "CCircle.h"
#include "My_storage.h"
#include "Thing.h"

namespace laba42 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>
    public ref class MyForm1 : public System::Windows::Forms::Form
    {
    public:
        MyForm1(void)
        {
            InitializeComponent();
            //
            //TODO: добавьте код конструктора
            //
        }

    protected:
        /// <summary>
        /// ќсвободить все используемые ресурсы.
        /// </summary>
        ~MyForm1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ btn_delete;







    protected:

    protected:


    protected:

    protected:

    protected:


    protected:

    protected:

    private:
        /// <summary>
        /// ќб€зательна€ переменна€ конструктора.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->btn_delete = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // btn_delete
            // 
            this->btn_delete->BackColor = System::Drawing::Color::SpringGreen;
            this->btn_delete->Location = System::Drawing::Point(771, 404);
            this->btn_delete->Name = L"btn_delete";
            this->btn_delete->Size = System::Drawing::Size(75, 23);
            this->btn_delete->TabIndex = 0;
            this->btn_delete->Text = L"Delete";
            this->btn_delete->UseVisualStyleBackColor = false;
            this->btn_delete->Click += gcnew System::EventHandler(this, &MyForm1::btn_delete_Click);
            // 
            // MyForm1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(858, 439);
            this->Controls->Add(this->btn_delete);
            this->KeyPreview = true;
            this->Name = L"MyForm1";
            this->Text = L"MyForm1";
            this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::MyForm1_Paint);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyDown);
            this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyUp);
            this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::MyForm1_MouseMove);
            this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::MyForm1_MouseUp);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MyForm1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
    {
        Graphics^ g = Graphics::FromHwnd(this->Handle);
        for (int i = 0; i < storage_ccircle->getCount(); i++)
        {
            storage_ccircle->getObject(i).drow(g);
        }
    }

    My_storage* storage_ccircle = new My_storage(0);

    private: System::Void MyForm1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
    {
        if (e->Button.ToString() == "Right")
        {
            storage_ccircle->addObjects(storage_ccircle->getCount(), new CCircle(e->X, e->Y));

            for (int i = 0; i < storage_ccircle->getCount() - 1; i++)
            {
                storage_ccircle->getObject(i).unselect();
            }

            Invalidate();
        }

        if (e->Button.ToString() == "Left")
        {
            for (int i = 0; i < storage_ccircle->getCount(); i++)
            {
                if (storage_ccircle->getObject(i).reach(e->X, e->Y) == true)
                {
                    storage_ccircle->getObject(i).select();
                    Invalidate();
                }
            }
        }
    }

    private: System::Void btn_delete_Click(System::Object^ sender, System::EventArgs^ e) 
    {

        for (int i = 0; i < storage_ccircle->getCount();)
        {
            if (storage_ccircle->getObject(i).is_select() == true)
            {
                storage_ccircle->deleteObject(i);
                i = 0;
            }
            else
                i++;
        }

        Invalidate();
    }

    bool marked_ctrl = false;

    private: System::Void MyForm1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
    {
        if (e->Control == true)
        {
            marked_ctrl = true;
        }
    }

   private: System::Void MyForm1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
   {
       marked_ctrl = false;
   }

   private: System::Void MyForm1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
   {
       if ((marked_ctrl == true) && e->Button.ToString() == "Left")
       {
           for (int i = 0; i < storage_ccircle->getCount(); i++)
           {
               if (storage_ccircle->getObject(i).reach(e->X, e->Y) == true)
               {
                   storage_ccircle->getObject(i).select();
               }
           }
           Invalidate();
       }
   }
};
}
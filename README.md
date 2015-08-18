Line Edits Example

http://doc.qt.digia.com/4.6/widgets-lineedits.html

The Line Edits example demonstrates the many ways that QLineEdit can be used,
and shows the effects of various properties and validators on the input and
output supplied by the user.

The example consists of a single Window class, containing a selection of line
edits with different input constraints and display properties that can be changed
by selecting items from comboboxes. Presenting these together helps developers
choose suitable properties to use with line edits, and makes it easy to compare
the effects of each validator on user input.

Window Class Definition

The Window class inherits QWidget and contains a constructor and several slots:

 class Window : public QWidget
 {
     Q_OBJECT

 public:
     Window();

 public slots:
     void echoChanged(int);
     void validatorChanged(int);
     void alignmentChanged(int);
     void inputMaskChanged(int);
     void accessChanged(int);

 private:
     QLineEdit *echoLineEdit;
     QLineEdit *validatorLineEdit;
     QLineEdit *alignmentLineEdit;
     QLineEdit *inputMaskLineEdit;
     QLineEdit *accessLineEdit;
 };

The slots are used to update the type of validator used for a given line edit when
a new validator has been selected in the associated combobox. The line edits are 
stored in the window for use in these slots.

Window Class Implementation

The Window constructor is used to set up the line edits, validators, and comboboxes,
connect signals from the comboboxes to slots in the Window class, and arrange the
child widgets in layouts.

We begin by constructing a group box to hold a label, combobox, and line edit so
that we can demonstrate the QLineEdit::echoMode property:

 Window::Window()
 {
     QGroupBox *echoGroup = new QGroupBox(tr("Echo"));

     QLabel *echoLabel = new QLabel(tr("Mode:"));
     QComboBox *echoComboBox = new QComboBox;
     echoComboBox->addItem(tr("Normal"));
     echoComboBox->addItem(tr("Password"));
     echoComboBox->addItem(tr("PasswordEchoOnEdit"));
     echoComboBox->addItem(tr("No Echo"));

     echoLineEdit = new QLineEdit;
     echoLineEdit->setFocus();

At this point, none of these widgets have been arranged in layouts. Eventually,
the echoLabel, echoComboBox, and echoLineEdit will be placed in a vertical layout
inside the echoGroup group box.

Similarly, we construct group boxes and collections of widgets to show the effects
of QIntValidator and QDoubleValidator on a line edit's contents:

     QGroupBox *validatorGroup = new QGroupBox(tr("Validator"));

     QLabel *validatorLabel = new QLabel(tr("Type:"));
     QComboBox *validatorComboBox = new QComboBox;
     validatorComboBox->addItem(tr("No validator"));
     validatorComboBox->addItem(tr("Integer validator"));
     validatorComboBox->addItem(tr("Double validator"));

     validatorLineEdit = new QLineEdit;

Text alignment is demonstrated by another group of widgets:

     QGroupBox *alignmentGroup = new QGroupBox(tr("Alignment"));

     QLabel *alignmentLabel = new QLabel(tr("Type:"));
     QComboBox *alignmentComboBox = new QComboBox;
     alignmentComboBox->addItem(tr("Left"));
     alignmentComboBox->addItem(tr("Centered"));
     alignmentComboBox->addItem(tr("Right"));

     alignmentLineEdit = new QLineEdit;

QLineEdit supports the use of input masks. These only allow the user to type characters
into the line edit that follow a simple specification. We construct a group of widgets
to demonstrate a selection of predefined masks:

     QGroupBox *inputMaskGroup = new QGroupBox(tr("Input mask"));

     QLabel *inputMaskLabel = new QLabel(tr("Type:"));
     QComboBox *inputMaskComboBox = new QComboBox;
     inputMaskComboBox->addItem(tr("No mask"));
     inputMaskComboBox->addItem(tr("Phone number"));
     inputMaskComboBox->addItem(tr("ISO date"));
     inputMaskComboBox->addItem(tr("License key"));

     inputMaskLineEdit = new QLineEdit;

Another useful feature of QLineEdit is its ability to make its contents read-only.
This property is used to control access to a line edit in the following group of widgets:

     QGroupBox *accessGroup = new QGroupBox(tr("Access"));

     QLabel *accessLabel = new QLabel(tr("Read-only:"));
     QComboBox *accessComboBox = new QComboBox;
     accessComboBox->addItem(tr("False"));
     accessComboBox->addItem(tr("True"));

     accessLineEdit = new QLineEdit;

Now that all the child widgets have been constructed, we connect signals from
the comboboxes to slots in the Window object:

     connect(echoComboBox, SIGNAL(activated(int)),
             this, SLOT(echoChanged(int)));
     connect(validatorComboBox, SIGNAL(activated(int)),
             this, SLOT(validatorChanged(int)));
     connect(alignmentComboBox, SIGNAL(activated(int)),
             this, SLOT(alignmentChanged(int)));
     connect(inputMaskComboBox, SIGNAL(activated(int)),
             this, SLOT(inputMaskChanged(int)));
     connect(accessComboBox, SIGNAL(activated(int)),
             this, SLOT(accessChanged(int)));

Each of these connections use the QComboBox::activated() signal that supplies an
integer to the slot. This will be used to efficiently make changes to the
appropriate line edit in each slot.

We place each combobox, line edit, and label in a layout for each group box,
beginning with the layout for the echoGroup group box:

     QGridLayout *echoLayout = new QGridLayout;
     echoLayout->addWidget(echoLabel, 0, 0);
     echoLayout->addWidget(echoComboBox, 0, 1);
     echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
     echoGroup->setLayout(echoLayout);

The other layouts are constructed in the same way:

     QGridLayout *validatorLayout = new QGridLayout;
     validatorLayout->addWidget(validatorLabel, 0, 0);
     validatorLayout->addWidget(validatorComboBox, 0, 1);
     validatorLayout->addWidget(validatorLineEdit, 1, 0, 1, 2);
     validatorGroup->setLayout(validatorLayout);

     QGridLayout *alignmentLayout = new QGridLayout;
     alignmentLayout->addWidget(alignmentLabel, 0, 0);
     alignmentLayout->addWidget(alignmentComboBox, 0, 1);
     alignmentLayout->addWidget(alignmentLineEdit, 1, 0, 1, 2);
     alignmentGroup-> setLayout(alignmentLayout);

     QGridLayout *inputMaskLayout = new QGridLayout;
     inputMaskLayout->addWidget(inputMaskLabel, 0, 0);
     inputMaskLayout->addWidget(inputMaskComboBox, 0, 1);
     inputMaskLayout->addWidget(inputMaskLineEdit, 1, 0, 1, 2);
     inputMaskGroup->setLayout(inputMaskLayout);

     QGridLayout *accessLayout = new QGridLayout;
     accessLayout->addWidget(accessLabel, 0, 0);
     accessLayout->addWidget(accessComboBox, 0, 1);
     accessLayout->addWidget(accessLineEdit, 1, 0, 1, 2);
     accessGroup->setLayout(accessLayout);

Finally, we place each group box in a grid layout for the Window object and
set the window title:

     QGridLayout *layout = new QGridLayout;
     layout->addWidget(echoGroup, 0, 0);
     layout->addWidget(validatorGroup, 1, 0);
     layout->addWidget(alignmentGroup, 2, 0);
     layout->addWidget(inputMaskGroup, 0, 1);
     layout->addWidget(accessGroup, 1, 1);
     setLayout(layout);

     setWindowTitle(tr("Line Edits"));
 }

The slots respond to signals emitted when the comboboxes are changed by the user.

When the combobox for the Echo group box is changed, the echoChanged() slot is called:

 void Window::echoChanged(int index)
 {
     switch (index) {
     case 0:
         echoLineEdit->setEchoMode(QLineEdit::Normal);
         break;
     case 1:
         echoLineEdit->setEchoMode(QLineEdit::Password);
         break;
     case 2:
         echoLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
         break;
     case 3:
         echoLineEdit->setEchoMode(QLineEdit::NoEcho);
     }
 }

The slot updates the line edit in the same group box to use an echo mode that
corresponds to the entry described in the combobox.

When the combobox for the Validator group box is changed, the validatorChanged()
slot is called:

 void Window::validatorChanged(int index)
 {
     switch (index) {
     case 0:
         validatorLineEdit->setValidator(0);
         break;
     case 1:
         validatorLineEdit->setValidator(new QIntValidator(
             validatorLineEdit));
         break;
     case 2:
         validatorLineEdit->setValidator(new QDoubleValidator(-999.0,
             999.0, 2, validatorLineEdit));
     }

     validatorLineEdit->clear();
 }

The slot either creates a new validator for the line edit to use, or it removes
the validator in use by calling QLineEdit::setValidator() with a zero pointer.
We clear the line edit in this case to ensure that the new validator is initially
given valid input to work with.

When the combobox for the Alignment group box is changed, the alignmentChanged()
slot is called:

 void Window::alignmentChanged(int index)
 {
     switch (index) {
     case 0:
         alignmentLineEdit->setAlignment(Qt::AlignLeft);
         break;
     case 1:
         alignmentLineEdit->setAlignment(Qt::AlignCenter);
         break;
     case 2:
         alignmentLineEdit->setAlignment(Qt::AlignRight);
     }
 }

This changes the way that text is displayed in the line edit to correspond with
the description selected in the combobox.

The inputMaskChanged() slot handles changes to the combobox in the Input Mask group box:

 void Window::inputMaskChanged(int index)
 {
     switch (index) {
     case 0:
         inputMaskLineEdit->setInputMask("");
         break;
     case 1:
         inputMaskLineEdit->setInputMask("+99 99 99 99 99;_");
         break;
     case 2:
         inputMaskLineEdit->setInputMask("0000-00-00");
         inputMaskLineEdit->setText("00000000");
         inputMaskLineEdit->setCursorPosition(0);
         break;
     case 3:
         inputMaskLineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
     }
 }

Each entry in the relevant combobox is associated with an input mask. We set a new mask
by calling the QLineEdit::setMask() function with a suitable string; the mask is
disabled if an empty string is used.

The accessChanged() slot handles changes to the combobox in the Access group box:

 void Window::accessChanged(int index)
 {
     switch (index) {
     case 0:
         accessLineEdit->setReadOnly(false);
         break;
     case 1:
         accessLineEdit->setReadOnly(true);
     }
 }

Here, we simply associate the False and True entries in the combobox with false and
true values to be passed to QLineEdit::setReadOnly(). This allows the user to enable
and disable input to the line edit.


create a new repository on the command line
-------------------------------------------
echo "# widgets" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:TradingLab/widgets.git
git push -u origin master

Push an existing repository from the command line
-------------------------------------------------
git remote add origin git@github.com:TradingLab/widgets.git
git push -u origin master

# Environment
* Operating System: openSUSE 13.1
* Development tool: KDevelop 4.5.2 for KDE 4.11.5
* Languaje: C++
* Program directory; HOME/TradingLab/widgets
* PostgreSQL lib: libpqxx


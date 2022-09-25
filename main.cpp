
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QPixmap>
#include <QSlider>
#include <QPainter>
#include <QPaintEvent>

class Circle : public QLabel {
  Q_OBJECT
private:
  QPixmap green;
  QPixmap red;
  QPixmap yellow;
  QPixmap current;
public:
  Circle() = default;
  Circle(QWidget* parent);
  void paintEvent(QPaintEvent* e) override;
  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;
  void currRed();
  void currYellow();
  void currGreen();
};

Circle::Circle(QWidget* parent) {
  setParent(parent);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  green.load("green.png");
  red.load("red.png");
  yellow.load("yellow.png");
  current = green;
  setGeometry(current.rect());
}

void Circle::paintEvent(QPaintEvent* e) {
  QPainter p(this);
  p.drawPixmap(e->rect(), current);
}

QSize Circle::sizeHint() const {
  return QSize(200, 200);
}

QSize Circle::minimumSizeHint() const {
  return sizeHint();
}

void Circle::currGreen() {
  current = green;
  update();
}

void Circle::currRed() {
  current = red;
  update();
}

void Circle::currYellow() {
  current = yellow;
  update();
}

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  QWidget  wgt;
  wgt.resize(300, 300);
  Circle* circle = new Circle(&wgt);
  auto* slider = new QSlider(Qt::Horizontal);
  slider->setRange(0, 100);

  QObject::connect(slider, &QSlider::valueChanged, [&slider, &circle](int newValue) {
    if (newValue > 30 && newValue < 60) {
      circle->currYellow();
    } else if (newValue > 60) {
       circle->currRed();
    } else {
      circle->currGreen();
    }
   });

  auto* Hlayout = new QHBoxLayout;
  auto* Vlayout = new QVBoxLayout;

  Hlayout->addWidget(circle, Qt::AlignCenter);
  Vlayout->addLayout(Hlayout);
  Vlayout->addWidget(slider);
  wgt.setLayout(Vlayout);
  wgt.show();
  return a.exec();
}

#include <main.moc>

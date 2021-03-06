/* This file was a part of qjson. Now is is a part of simula
  *
  * Tony :)
  *
  */

#ifndef QOBJECTHELPER_H
#define QOBJECTHELPER_H


#include <QtCore/QLatin1String>
#include <QtCore/QStringList>
#include <QtCore/QVariantMap>

QT_BEGIN_NAMESPACE
class QObject;
QT_END_NAMESPACE

namespace QJson {
  /**
  * @brief Class used to convert QObject into QVariant and vivce-versa.
  * During these operations only the class attributes defined as properties will
  * be considered.
  * Properties marked as 'non-stored' will be ignored.
  *
  * Suppose the declaration of the Person class looks like this:
  * \code
  * class Person : public QObject
    {
      Q_OBJECT

      Q_PROPERTY(QString name READ name WRITE setName)
      Q_PROPERTY(int phoneNumber READ phoneNumber WRITE setPhoneNumber)
      Q_PROPERTY(Gender gender READ gender WRITE setGender)
      Q_PROPERTY(QDate dob READ dob WRITE setDob)
      Q_ENUMS(Gender)

     public:
        Person(QObject* parent = 0);
        ~Person();

        QString name() const;
        void setName(const QString& name);

        int phoneNumber() const;
        void setPhoneNumber(const int  phoneNumber);

        enum Gender {Male, Female};
        void setGender(Gender gender);
        Gender gender() const;

        QDate dob() const;
        void setDob(const QDate& dob);

      private:
        QString m_name;
        int m_phoneNumber;
        Gender m_gender;
        QDate m_dob;
    };
    \endcode

    The following code will serialize an instance of Person to JSON :

    \code
    Person person;
    person.setName("Flavio");
    person.setPhoneNumber(123456);
    person.setGender(Person::Male);
    person.setDob(QDate(1982, 7, 12));

    QVariantMap variant = QObjectHelper::qobject2qvariant(&person);
    Serializer serializer;
    qDebug() << serializer.serialize( variant);
    \endcode

    The generated output will be:
    \code
    { "dob" : "1982-07-12", "gender" : 0, "name" : "Flavio", "phoneNumber" : 123456 }
    \endcode

    It's also possible to initialize a QObject using the values stored inside of
    a QVariantMap.

    Suppose you have the following JSON data stored into a QString:
    \code
    { "dob" : "1982-07-12", "gender" : 0, "name" : "Flavio", "phoneNumber" : 123456 }
    \endcode

    The following code will initialize an already allocated instance of Person
    using the JSON values:
    \code
    Parser parser;
    QVariant variant = parser.parse(json);

    Person person;
    QObjectHelper::qvariant2qobject(variant.toMap(), &person);
    \endcode

    \sa Parser
    \sa Serializer
  */
  class QObjectHelper {
    public:
      QObjectHelper();
      ~QObjectHelper();

    /**
    * This method converts a QObject instance into a QVariantMap.
    *
    * @param object The QObject instance to be converted.
    * @param ignoredProperties Properties that won't be converted.
    */
    static QVariantMap qobject2qvariant( const QObject* object,
                                  const QStringList& ignoredProperties = QStringList(QString(QLatin1String("objectName"))));

    /**
    * This method converts a QVariantMap instance into a QObject
    *
    * @param variant Attributes to assign to the object.
    * @param object The QObject instance to update.
    */
    static void qvariant2qobject(const QVariantMap& variant, QObject* object);

    private:
      Q_DISABLE_COPY(QObjectHelper)
      class QObjectHelperPrivate;
      QObjectHelperPrivate* const d;
  };
}

#endif // QOBJECTHELPER_H

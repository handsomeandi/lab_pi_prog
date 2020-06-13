#ifndef TST_TEST9LAB_H
#define TST_TEST9LAB_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IKeypad.h>
#include <ILatch.h>
#include <lockcontroller.h>

using namespace testing;

class MockLatch : public ILatch
{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(DoorStatus, open, (), (override));
    MOCK_METHOD(DoorStatus, close, (), (override));
    MOCK_METHOD(DoorStatus, getDoorStatus, (), (override));
};

class MockKeypad : public IKeypad
{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(void, wait, (), (override));
    MOCK_METHOD(PasswordResponse, requestPassword, (), (override));
};

class LockControllFixture : public Test
{
public:
    MockKeypad keypad;
    MockLatch latch;
    LockController* lc;

    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override
    {
        lc = new LockController(&keypad, &latch);
    }
    void TearDown() override
    {
        delete lc;
    };
};

// Test_1
TEST_F(LockControllFixture, checkwait)
{
    // Arrange
    EXPECT_CALL(keypad, wait())
            .Times(1)
            .WillOnce(Return());

    // Act
    lc->wait();

    // Assert
}

//Test_2
TEST_F(LockControllFixture, DoorClosedCheckDoorOpen)
{
    // Arrange
    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));

    // Act
    bool res = lc->isDoorOpen();

    // Assert
    ASSERT_FALSE(res);
}

//Test_3
TEST_F(LockControllFixture, DoopOpenCheckDoorOpen)
{
    // Arrange
    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));

    //Act
    bool res = lc->isDoorOpen();

    // Assert
    ASSERT_TRUE(res);
}

//Test_4
TEST_F(LockControllFixture, LockControllerOpen)
{
   // Arrange
    EXPECT_CALL(latch, open())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));

   // Act
    DoorStatus res = lc->unlockDoor();

   // Assert
    ASSERT_EQ(res, DoorStatus::OPEN);
}

//Test_5
TEST_F(LockControllFixture, LockControllerClosing)
{
    // Arrange
    EXPECT_CALL(latch, close())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));
    // Act
    auto res = lc->lockDoor();

    // Assert
    ASSERT_EQ(res, DoorStatus::CLOSE);
}

//Test_6
TEST_F(LockControllFixture, HardwareOK)
{
    // Arrange
    EXPECT_CALL(keypad, isActive())
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(latch, isActive())
            .Times(1)
            .WillOnce(Return(true));

    // Act
    HardWareStatus res = lc->hardWareCheck();

    // Assert
    ASSERT_EQ(res, HardWareStatus::OK);
}

//Test_7
TEST_F(LockControllFixture, HardwareNotOK)
{
    // Arrange
    delete lc;

    lc = new LockController(nullptr, &latch);

    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));
    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));

    // Act
    HardWareStatus res = lc->hardWareCheck();

    // Assert
    ASSERT_EQ(res, HardWareStatus::ERROR);
}

//Test_8
TEST_F(LockControllFixture, LatchNotWork)
{
    // Arrange
        EXPECT_CALL(keypad, isActive())
                .Times(AtLeast(0))
                .WillOnce(Return(true));
        EXPECT_CALL(latch, isActive())
                .Times(AtLeast(0))
                .WillOnce(Return(false));

        // Act
        HardWareStatus res = lc->hardWareCheck();

        // Assert
        ASSERT_EQ(res, HardWareStatus::ERROR);
}


//Test_9
TEST_F(LockControllFixture, PasswordOK) {
    // Arrange
    PasswordResponse passwordOK;

    passwordOK.password = "0000";
    passwordOK.status = PasswordResponse::Status::OK;
    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(passwordOK));

    // Act
    bool res = lc->isCorrectPassword();

    // Assert
    ASSERT_TRUE(res);
}

//Test_10
TEST_F(LockControllFixture, PassworkNotOK) {
    // Arrange
    PasswordResponse passwordNotOK;

    passwordNotOK.password = "2859";
    passwordNotOK.status = PasswordResponse::Status::OK;

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(passwordNotOK));

    // Act
    bool res = lc->isCorrectPassword();

    // Assert
    ASSERT_FALSE(res);
}

//Test_11
TEST_F(LockControllFixture, PasswordChangeOK)
{
    // Arrange
       PasswordResponse passChangeOK1;
       passChangeOK1.password = "0000";
       passChangeOK1.status = PasswordResponse::Status::OK;

       PasswordResponse passChangeOK2;
       passChangeOK2.password = "3248";
       passChangeOK2.status = PasswordResponse::Status::OK;

       PasswordResponse passChangeOK3;
       passChangeOK3.password = "3289";
       passChangeOK3.status = PasswordResponse::Status::OK;

       EXPECT_CALL(keypad, requestPassword())
               .Times(3)
               .WillOnce(Return(passChangeOK1))
               .WillOnce(Return(passChangeOK2))
               .WillOnce(Return(passChangeOK3));

       // Act
       lc->resetPassword();
       auto res = lc->isCorrectPassword();

       // Assert
       ASSERT_TRUE(res);
}

//Test_12
TEST_F(LockControllFixture, AnotherPasswordChangeOK)
{
    // Arrange
        PasswordResponse passChangeOK1;
        passChangeOK1.password = "0000";
        passChangeOK1.status = PasswordResponse::Status::OK;

        PasswordResponse passChangeOK2;
        passChangeOK2.password = "9876";
        passChangeOK2.status = PasswordResponse::Status::OK;

        PasswordResponse passChangeOK3;
        passChangeOK3.password = "9876";
        passChangeOK3.status = PasswordResponse::Status::OK;

        PasswordResponse passChangeOK4;
        passChangeOK4.password = "4894";
        passChangeOK4.status = PasswordResponse::Status::OK;

        PasswordResponse passChangeOK5;
        passChangeOK5.password = "4859";
        passChangeOK5.status = PasswordResponse::Status::OK;

        EXPECT_CALL(keypad, requestPassword())
                .Times(5)
                .WillOnce(Return(passChangeOK1))
                .WillOnce(Return(passChangeOK2))
                .WillOnce(Return(passChangeOK3))
                .WillOnce(Return(passChangeOK4))
                .WillOnce(Return(passChangeOK5));

        // Act
        lc->resetPassword();
        lc->resetPassword();
        auto res = lc->isCorrectPassword();

        // Assert
        ASSERT_TRUE(res);
}


//TEST(Test9Lab, Test9Lab)
//{
//    EXPECT_EQ(1, 1);
//    ASSERT_THAT(0, Eq(0));
//}

#endif // TST_TEST9LAB_H
